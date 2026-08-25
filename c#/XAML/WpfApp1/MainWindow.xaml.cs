using System.Collections.ObjectModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;


namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public ObservableCollection<string> AutoCompleteItems { get; set; }
        public MainWindow()
        {
            InitializeComponent();
            PopulateComboBox();
            DataContext = this;
            AutoCompleteItems = new ObservableCollection<string>
            {
                "Apple",
                "Banana",
                "Cherry",
                "Date",
                "Elderberry",
                "Fig",
                "Grape"
            };
        }

        private void PopulateComboBox()
        {
            cmbOptions.Items.Add("Option 1");
            cmbOptions.Items.Add("Option 2");
            cmbOptions.Items.Add("Option 3");
        }
    }

    public static class AutoCompleteBehavior
    {
        public static readonly DependencyProperty AutoCompleteItemsSourceProperty =
            DependencyProperty.RegisterAttached("AutoCompleteItemsSource", typeof(ObservableCollection<string>), typeof(AutoCompleteBehavior), new PropertyMetadata(null, OnAutoCompleteItemsSourceChanged));

        public static ObservableCollection<string> GetAutoCompleteItemsSource(DependencyObject obj)
        {
            return (ObservableCollection<string>)obj.GetValue(AutoCompleteItemsSourceProperty);
        }

        public static void SetAutoCompleteItemsSource(DependencyObject obj, ObservableCollection<string> value)
        {
            obj.SetValue(AutoCompleteItemsSourceProperty, value);
        }

        private static void OnAutoCompleteItemsSourceChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            if (d is TextBox textBox)
            {
                textBox.TextChanged -= OnTextChanged;
                textBox.TextChanged += OnTextChanged;
            }
        }

        private static void OnTextChanged(object sender, TextChangedEventArgs e)
        {
            if (sender is TextBox textBox)
            {
                var itemsSource = GetAutoCompleteItemsSource(textBox);
                if (itemsSource != null)
                {
                    var popup = new Popup
                    {
                        PlacementTarget = textBox,
                        StaysOpen = false,
                        IsOpen = true,
                        Child = new ListBox
                        {
                            ItemsSource = itemsSource,
                            Width = textBox.ActualWidth
                        }
                    };

                    popup.Child.PreviewMouseLeftButtonUp += (s, args) =>
                    {
                        if (popup.Child is ListBox listBox && listBox.SelectedItem != null)
                        {
                            textBox.Text = listBox.SelectedItem.ToString();
                            popup.IsOpen = false;
                        }
                    };
                }
            }
        }
    }

}
