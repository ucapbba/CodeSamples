﻿using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.Collections.Generic;
using System.Collections.ObjectModel;

namespace MauiApp1.ViewModel
{
    public partial class MainViewModel : ObservableObject
    {

        public MainViewModel() 
        {
            ReloadFromServer();
        }
        public void ReloadFromServer()
        {
            List<TodoModel> currentItems = myRESTAPI.Get();
            int size = currentItems.Count;
            ObservableCollection<string> collection = new ObservableCollection<string>();
            foreach (TodoModel item in currentItems)
            {
                collection.Add(item.name);
            }

            Items = collection;
        }
        [ObservableProperty]
        ObservableCollection<string>   _items;

        [ObservableProperty]
        string text;

        [RelayCommand]
        void Add()
        {
           
            if (string.IsNullOrEmpty(Text))
            {
                return;
            }
            if(myRESTAPI.success==false)
                ReloadFromServer();

            Items.Add(Text);
            List<TodoModel> currentItemsTask = myRESTAPI.Get();
            List<TodoModel> currentItems = currentItemsTask;
            int size = currentItems.Count;
            myRESTAPI.Post(size + 1, Text);
            Text = string.Empty;
        }

        [RelayCommand]
        void Delete(string s)
        {
            if(Items.Contains(s)) { Items.Remove(s); }
            List <TodoModel> currentItems = myRESTAPI.Get();
            int? id = currentItems.Where(a => a.name == s).FirstOrDefault().id;
            myRESTAPI.delete((int)id);
        }

    }
}
