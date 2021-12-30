using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using DevExpress.XtraEditors;
using DevExpress.XtraEditors.Repository;

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

            //Add repo toggle to grid control
            RepositoryItemToggleSwitch edit = new RepositoryItemToggleSwitch();
            edit.OnText = "Enabled";
            edit.OffText = "Disabled";
            gridControl1.RepositoryItems.Add(edit);
            gridView1.Columns["Mark"].ColumnEdit = edit;

            DataTable table = new DataTable();
            table.Columns.Add("Param");
            table.Columns.Add("Mark");
            DataRow row = table.NewRow();
            row[0] = "test";
            table.Rows.Add(row);

            gridControl1.DataSource = table;
        }
    }
}