using DevExpress.XtraBars;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DXApplication3_GridView_Docking
{
    public partial class Form1 : DevExpress.XtraEditors.XtraForm
    {
        public Form1()
        {
            InitializeComponent();
           // gridControl1.DataSource = DataHelper.GetBasicData();
        }

        private void btnDoStuff_ItemClick(object sender, ItemClickEventArgs e)
        {
            gridControl1.DataSource = DataHelper.GetData(10);
        }

        private void gridControl1_Click(object sender, EventArgs e)
        {
            if(gridControl1.DataSource==null)
                gridControl1.DataSource = DataHelper.GetData(10);
        }
    }



    public class Record
    {
        public Record()
        {
        }
        int positionId;
        public int posID
        {
            get { return positionId; }
            set
            {
                if (positionId != value)
                {
                    positionId = value;
                }
            }
        }

        string text;
        [DisplayName("InstrumentName")]
        public string InstrumentName
        {
            get { return text; }
            set
            {
                if (text != value)
                {
                    if (string.IsNullOrEmpty(value))
                        throw new Exception();
                    text = value;
                }
            }
        }

        public static BindingList<Record> GetData(int count)
        {
            BindingList<Record> records = new BindingList<Record>();
            Random rnd = new Random();
            for (int i = 0; i < count; i++)
            {
                int n = rnd.Next(10);
                records.Add(new Record()
                {
                    positionId = i + 100,
                });
            };
            return records;
        }
    }

    public class DataHelper
    {
        public static string[] instruments = new string[] { "Apple", "Orangle", "Romero y tomillo", "ABN Amro" };
        public static BindingList<Record> GetData(int count)
        {


            BindingList<Record> records = new BindingList<Record>();
            Random rnd = new Random();
            for (int i = 0; i < count; i++)
            {
                int n = rnd.Next(10);
                records.Add(new Record()
                {
                    posID = i + 100,
                    InstrumentName = instruments[i % instruments.Length],
                });
            };
            return records;
        }
        public static BindingList<string> GetBasicData()
        {


            BindingList<string> records = new BindingList<string>();
          
                records.Add("Hello2 World");
            return records;
        }
    }

}
