using System;
using System.ComponentModel;
using System.Data;
using DevExpress.XtraEditors;
using DevExpress.XtraEditors.Repository;
using System.Runtime.CompilerServices;
using Microsoft.Data.Sqlite;
using System.Collections.Generic;

namespace DropDown
{
    public partial class Form : DevExpress.XtraEditors.XtraForm
    {

        public Form()
        {
            InitializeComponent();

            //dynamically creates a toggle on winform
            var myToggleSwitch = new ToggleSwitch();
            myToggleSwitch.Width = 200;
            //access a repository item
            var repoItem = myToggleSwitch.Properties;
            repoItem.OnText = "Enabled";
            repoItem.OffText = "Disabled";
            this.Controls.Add(myToggleSwitch);

            //this.textEdit1.Properties  //get only


            //Add repo toggle to grid control
            RepositoryItemToggleSwitch edit = new RepositoryItemToggleSwitch();
            edit.OnText = "Enabled";
            edit.OffText = "Disabled";
            gridControl1.RepositoryItems.Add(edit);
            gridView1.Columns["Mark"].ColumnEdit = edit;

            //add combo to column
            RepositoryItemComboBox riComboBox = new RepositoryItemComboBox();
            riComboBox.Items.AddRange(DataHelper.companies);
            gridControl1.RepositoryItems.Add(riComboBox);
            gridView1.Columns["ComboStatic"].ColumnEdit = riComboBox;

            string path = "C:/GIT/CodeSamples/DevExpress/DropDown/";

            List<string> petNames = new List<string>();
            using (var connection = new SqliteConnection("Data Source="+path+"DropDown.db"))
            {
                connection.Open();

                var command = connection.CreateCommand();
                command.CommandText = "select name from MyPets;";
                //command.Parameters.AddWithValue("$name", id);

                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        var name = reader.GetString(0);
                        petNames.Add(name);
                        Console.WriteLine($"Hello, {name}!");
                    }
                }
            }

            //add combo to column
            RepositoryItemComboBox riComboBox2 = new RepositoryItemComboBox();
            riComboBox2.Items.AddRange(petNames);
            gridControl1.RepositoryItems.Add(riComboBox2);
            gridView1.Columns["ComboDB"].ColumnEdit = riComboBox2;

            //add a row with DataTable
            DataTable table = new DataTable();
            table.Columns.Add("Param");
            table.Columns.Add("Mark");
            table.Columns.Add("ComboStatic");
            table.Columns.Add("ComboDB");
            DataRow row = table.NewRow();
            row[0] = "testParam";
            row[2] = "testComboStatic";
            row[2] = "testComboDB";
            table.Rows.Add(row);

            gridControl1.DataSource = table;
        }



        private void gridControl2_Click(object sender, EventArgs e)
        {

        }
    }
}