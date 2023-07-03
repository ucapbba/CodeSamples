using DevExpress.XtraTreeList;
using DevExpress.XtraTreeList.Nodes;
using DevExpress.XtraTreeList.Printing;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DXApplication3_TreeList
{
    public partial class Form1 : DevExpress.XtraEditors.XtraForm
    {
        public Form1()
        {
            InitializeComponent();
            treeList1.DataSource = DataHelper.CreateTLData(10);
            //DataTable table = (DataTable)treeList1.DataSource;
        }

        private void simpleButton1_Click(object sender, EventArgs e)
        {
            this.SuspendLayout();
            treeList1.DataSource = DataHelper.CreateTLData(4);
            //DataTable table = (DataTable)treeList1.DataSource;

        }

        private void treeList1_ClipboardNodeCopying(object sender, ClipboardNodeCopyingEventArgs e)
        {
            //not called on Cntrl+C.....
            ClipboardValueInfoCollection values = e.Values;
        }

        private void treeList1_KeyDown(object sender, KeyEventArgs e)
        {
            Console.Write("called");
            if (e.Control && e.KeyCode == Keys.C)
            {
                // Customizing the copied text
                TreeListNode selectedNode = treeList1.FocusedNode;
                string customText = $"Custom text: {selectedNode["ColumnName"]}";

                // Copy the custom text to the clipboard
                Clipboard.SetText(customText);

                // Mark the event as handled to prevent further processing
                e.Handled = true;
            }
        }

    }

    public class DataHelper
    {
        public static DataTable CreateTLData(int recordCount)
        {
            Random rnd = new Random();
            DataTable tbl = new DataTable();
            tbl.Columns.Add("ID", typeof(int));
            tbl.Columns.Add("ParentID", typeof(int));
            tbl.Columns.Add("Name", typeof(string));
            tbl.Columns.Add("Date", typeof(DateTime));
            tbl.Columns.Add("Checked", typeof(bool));
            for (int i = 0; i < recordCount; i++)
                tbl.Rows.Add(new object[] { i, rnd.Next(20), String.Format("Name{0}", i), DateTime.Now.Date.AddDays(rnd.Next(-250, 250)), rnd.Next(2) == 0 });
            return tbl;
        }
    }
}
