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

        private void button1_Click(object sender, EventArgs e)
        {
            //update panel 1
            textBox1.Text = "updated";
            this.tableLayoutPanel1.RowCount += 1;
            this.tableLayoutPanel1.Controls.Add(new Label { Text = "My Instrument 1", Anchor = AnchorStyles.Left, AutoSize = true }, 0, this.tableLayoutPanel1.RowCount);
            this.tableLayoutPanel1.Controls.Add(new Label { Text = "My Folio", Anchor = AnchorStyles.Left, AutoSize = true }, 1, this.tableLayoutPanel1.RowCount);
            this.tableLayoutPanel1.Controls.Add(new Label { Text = "My Folio Path", Anchor = AnchorStyles.Left, AutoSize = true }, 2, this.tableLayoutPanel1.RowCount);
            this.tableLayoutPanel1.Refresh();
     
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
