using System;
using System.ComponentModel;
using System.Data;
using DevExpress.XtraEditors;
using DevExpress.XtraEditors.Repository;
using System.Runtime.CompilerServices;

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
            gridView1.Columns["Combo"].ColumnEdit = riComboBox;


            //add a row with DataTable
            DataTable table = new DataTable();
            table.Columns.Add("Param");
            table.Columns.Add("Mark");
            table.Columns.Add("Combo");
            DataRow row = table.NewRow();
            row[0] = "testParam";
            row[2] = "testCombo";
            table.Rows.Add(row);

            gridControl1.DataSource = table;
        }
    }
}