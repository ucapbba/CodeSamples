using System.Data;
using DataView = DevExpress.DataAccess.Native.Excel.DataView;
using System.Numerics;
using System;
using System.Windows.Forms;

namespace Frankenstein
{
    class InputManaged
    {
        public InputManaged(DataView resultView)
        {
            try
            {
                DataTable dt = new DataTable("MyTable");
                resultView.Columns.ForEach(col => dt.Columns.Add(new DataColumn(col.Name, col.PropertyType)));
                foreach (DevExpress.DataAccess.Native.Excel.ViewRow row in resultView)
                {
                    object[] value = new object[resultView.Columns.Count]; //should be 2
                    for (int i = 0; i < resultView.Columns.Count; i++)
                    {
                        value[i] = resultView.Columns[i].GetValue(row);
                    }

                    if (value[0].ToString() == "Up")
                        Up = (double)value[1];

                    if (value[0].ToString() == "Omega")
                        omega = (double)value[1];

                    if (value[0].ToString() == "E1g")
                        E1g = (double)value[1];

                    if (value[0].ToString() == "E2g")
                        E2g = (double)value[1];

                    if (value[0].ToString() == "E2e")
                        E2e = (double)value[1];

                    if (value[0].ToString() == "p_parallel_max")
                        p_max = (double)value[1];

                    if (value[0].ToString() == "p_parallel_min")
                        p_min = (double)value[1];

                    if (value[0].ToString() == "dp")
                        dp = (double)value[1];

                    if (value[0].ToString() == "p_perp_max")
                        p_perp_max = (double)value[1];

                    if (value[0].ToString() == "p_perp_min")
                        p_perp_min = (double)value[1];

                    if (value[0].ToString() == "dp")
                        dp_perp = (double)value[1];
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("Unable to obtain input data : " + e.Message);
            }

            //N.B not able to retireve complex from grid view 
            t1short = new Complex(1.71343 / omega, 1.27339 / omega);
            t2short = new Complex(6.0649 / omega, 1.21389 / omega);
            t3short = new Complex(6.85759 / omega, 1.75491 / omega);
            t1long = new Complex(1.83515 / omega, 0.719401 / omega);
            t1long = new Complex(7.0701 / omega, 1.18486 / omega);
            t1long = new Complex(6.8 / omega, 1.75491 / omega); //probably not required.
        }

        public double Up { get; set; }
        public double omega { get; set; }
        public double E1g { get; set; }
        public double E2g { get; set; }
        public double E2e { get; set; }
        public double p_max { get; set; }
        public double p_min { get; set; }
        public double dp { get; set; }
        public double p_perp_max { get; set; }
        public double p_perp_min { get; set; }
        public double dp_perp { get; set; }
        public Complex t1short { get; set; }
        public Complex t2short { get; set; }
        public Complex t3short { get; set; }
        public Complex t1long { get; set; }
        public Complex t2long { get; set; }
        public Complex t3long { get; set; }

    }
}
