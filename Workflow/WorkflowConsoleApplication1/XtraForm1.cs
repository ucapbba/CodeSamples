using DevExpress.XtraEditors;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WorkflowConsoleApplication1
{
    public partial class XtraForm1 : DevExpress.XtraEditors.XtraForm
    {
        private FormClosedEventHandler _formClosedHandler;
        public XtraForm1(string inputText)
        {
            InitializeComponent();
            // Subscribe to the FormClosed event
            _formClosedHandler = new FormClosedEventHandler(PopupForm_FormClosed);
            this.textBox1.Text = inputText;
            this.FormClosed += _formClosedHandler; 
        }

        public string InputValue { get; private set; }

        private void PopupForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            // Unsubscribe the event handler
            this.FormClosed -= _formClosedHandler;

            // Raise the FormClosed event using the base class's OnFormClosed method
            base.OnFormClosed(e);

            // Resubscribe the event handler
            this.FormClosed += _formClosedHandler;
        }
        private void simpleButton1_Click(object sender, EventArgs e)
        {
            InputValue = this.textBox2.Text;
            DialogResult = DialogResult.OK;
            this.Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}