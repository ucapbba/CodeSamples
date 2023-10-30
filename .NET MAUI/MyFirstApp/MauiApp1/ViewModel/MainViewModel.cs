using System.ComponentModel;

namespace MauiApp1.ViewModel
{
    public class MainViewModel : INotifyPropertyChanged
    {
        string text;

        public string Text
        {
            get => text;
            set
            {
               text = value;
                OnPropertChanged(nameof(Text));

            }
        }
        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertChanged(string name)=>
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
    }
}
