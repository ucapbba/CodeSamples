using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.Collections.ObjectModel;

namespace MauiApp1.ViewModel
{
    public partial class MainViewModel : ObservableObject
    {

        public MainViewModel() 
        {


            Items = new ObservableCollection<string>();
        }

        [ObservableProperty]
        ObservableCollection<string>   _items;

        [ObservableProperty]
        string text;

        [RelayCommand]
        void Add()
        {
            if(string.IsNullOrEmpty(Text))
            {
                return;
            }

            Items.Add(Text);
            Text = string.Empty;
        }

        [RelayCommand]
        void Delete(string s)
        {
            if(Items.Contains(s)) { Items.Remove(s); }
        }

    }
}
