using DevExpress.Utils;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DXApplication3_GridView
{
    public partial class Form1 : DevExpress.XtraEditors.XtraForm
    {
        private int rows = 10;

        public Form1()
        {
            InitializeComponent();
            gridControl1.DataSource = DataHelper.GetData(rows);
            gridView1.Columns.ToList().LastOrDefault(a => a.CustomizationSearchCaption == "Position Id").AppearanceCell.TextOptions.HAlignment = HorzAlignment.Far;
            gridView1.OptionsView.ColumnAutoWidth = true;
        }

        private void simpleButton1_Click(object sender, EventArgs e)
        {
            rows += 10;
            gridControl1.DataSource = DataHelper.GetData(rows);
        }

        private void simpleButton2_Click(object sender, EventArgs e)
        {
            if (rows < 10) return;
            rows -= 10;
            
            gridControl1.DataSource = DataHelper.GetData(rows);

        }
    }

    public class Record 
    {
        public Record()
        {
        }
        string positionId;
        [DisplayName("Position Id")]
        public string posID
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

    }

    public class DataHelper
    {
        public static string[] instruments = new string[] { "Apple sadfsdfsdfsadfsdfsdfsdfwqesdfwqe", "Orangle sadfsdfsdsadfsdfsdfsdfwqefsdfwqe", "Romero y tomillo sadfsdfssadfsdfsdfsdfwqedfsdfwqe", "ABN Amro sadfsdsadfsdfsdfsdfwqefsdfsdfwqe" };
        public static BindingList<Record> GetData(int count)
        {


        BindingList<Record> records = new BindingList<Record>();
            Random rnd = new Random();
            for (int i = 0; i < count; i++)
            {
                int n = rnd.Next(10);
                double value = ((i + 11111111) / 100.00);
                records.Add(new Record()
                {
                    posID = value.ToString("N0", CultureInfo.InvariantCulture),
                    InstrumentName = instruments[i % instruments.Length],
                });
            };
            return records;
        }
    }

}
