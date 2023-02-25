using DevExpress.XtraSplashScreen;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AsyncDialog
{
    public partial class Form1 : DevExpress.XtraEditors.XtraForm
    {
        public Form1()
        {
            InitializeComponent();
        }
        private WindowsFormsSynchronizationContext context;
        private void Form1_Load(object sender, EventArgs e)
        {
            // Instead of invoke, Create a new instance of WindowsFormsSynchronizationContext
            context = new WindowsFormsSynchronizationContext();

        }

        private async void simpleButton1_Click(object sender, EventArgs e)
        {
            await Task.Run(() => MyMethod()); //asynchronious 
        }

        private async void MyMethod()
        {
            Invoke((Action)delegate //ensures update to GUI done with UI master / control thread
            {
                this.simpleButton1.Enabled = false;
                textEdit2.Text = "calcualtion in progress.....";
            });
            await Task.Delay(4000); 
            //Thread.Sleep(2000); Delay means in principle the thread can be used for other work

            Invoke((Action)delegate //ensures update to GUI done with UI master / control thread
            {
                this.simpleButton1.Enabled = true;
                textEdit2.Text = "calcualtion complete";
            });
        }

    }
}
