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
                    this.tableLayoutPanel1.Controls.RemoveAt(3); //repeatedly remove first value
                    
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

            //int currentIndex = this.tableLayoutPanel1.RowCount * 3 - 1;

            this.tableLayoutPanel1.Controls[3].AccessibleRole = AccessibleRole.Text;    
            this.tableLayoutPanel1.Controls[3].MouseHover += new System.EventHandler(this.mouse_hover);
            ToolTip tip = new ToolTip();
            tip.SetToolTip(this.tableLayoutPanel1.Controls[3], "click to copy");
            this.tableLayoutPanel1.Controls[3].Click += new System.EventHandler(this.name_click);
      


            if (this.tableLayoutPanel1.RowCount > 5)
            {
                Size minSize = new Size(this.Size.Width + 500, this.Size.Height);
                this.tableLayoutPanel1.AutoScrollMinSize = minSize;
            }

        }
        private void mouse_hover(object sender, EventArgs e)
        {
          
        }
        private void name_click(object sender, EventArgs e)
        {
            string name = this.tableLayoutPanel1.Controls[3].Text;
            System.Windows.Forms.Clipboard.SetText(name);
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

       
        
    }
}
