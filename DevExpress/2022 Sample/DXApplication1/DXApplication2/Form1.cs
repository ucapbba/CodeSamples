using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DXApplication2
{
    public partial class Form1 : DevExpress.XtraEditors.XtraForm
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (this.tableLayoutPanel1.RowCount > 0)
            {
                for (int i = 0; i < this.tableLayoutPanel1.RowCount * 3; i++)
                {
                    this.tableLayoutPanel1.Controls.RemoveAt(3); //this is horrific but it works 
                    
                }
                this.tableLayoutPanel1.RowCount = 0;
                this.tableLayoutPanel1.Update();
            }


        }

            private void button1_Click(object sender, EventArgs e)
        {
            //update panel 1
            textBox1.Text = "updated";
            this.tableLayoutPanel1.RowCount += 1;
            this.tableLayoutPanel1.Controls.Add(new Label { Text = "My Instrument 1", Anchor = AnchorStyles.Left, AutoSize = true }, 0, this.tableLayoutPanel1.RowCount);
            this.tableLayoutPanel1.Controls.Add(new Label { Text = "My Folio", Anchor = AnchorStyles.Left, AutoSize = true }, 1, this.tableLayoutPanel1.RowCount);
            this.tableLayoutPanel1.Controls.Add(new Label { Text = "My Folio Path", Anchor = AnchorStyles.Left, AutoSize = true }, 2, this.tableLayoutPanel1.RowCount);
            this.tableLayoutPanel1.Refresh();

            if (this.tableLayoutPanel1.RowCount > 5)
            {
                Size minSize = new Size(this.Size.Width + 500, this.Size.Height);
                this.tableLayoutPanel1.AutoScrollMinSize = minSize;
            }

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if(this.checkBox1.Checked)
            {
                this.textBox2.Text = "updated";
            }
            else
            {
                this.textBox2.Text = "reverted";
            }
        }

        public static class TableLayoutHelper
        {
            public static void RemoveArbitraryRow(TableLayoutPanel panel, int rowIndex)
            {
                if (rowIndex >= panel.RowCount)
                {
                    return;
                }

                // delete all controls of row that we want to delete
                for (int i = 0; i < panel.ColumnCount; i++)
                {
                    var control = panel.GetControlFromPosition(i, rowIndex);
                    panel.Controls.Remove(control);
                }

                // move up row controls that comes after row we want to remove
                for (int i = rowIndex + 1; i < panel.RowCount; i++)
                {
                    for (int j = 0; j < panel.ColumnCount; j++)
                    {
                        var control = panel.GetControlFromPosition(j, i);
                        if (control != null)
                        {
                            panel.SetRow(control, i - 1);
                        }
                    }
                }

                var removeStyle = panel.RowCount - 1;

                if (panel.RowStyles.Count > removeStyle)
                    panel.RowStyles.RemoveAt(removeStyle);

                panel.RowCount--;
            }
        }
    }
}
