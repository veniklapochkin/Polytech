using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Oracle.ManagedDataAccess.Client;
using Oracle.ManagedDataAccess.Types;

namespace Bookkeeping
{
    public partial class ChangeBalance : Form
    {
        string conString = "DATA SOURCE=localhost:1521/orcl;USER ID=VLAD_BORISOV;Password=0000";
        public ChangeBalance()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string Query = "Update Balance set debit=(SELECT DEBIT FROM(SELECT*FROM OPERATIONS WHERE CREATE_DATE BETWEEN '" + this.CREATE_DATE_BEGIN.Text + "' AND '" + this.create_date_end.Text + "' ORDER BY DEBIT) WHERE ROWNUM=1),credit=(SELECT SUM(CREDIT) FROM OPERATIONS WHERE CREATE_DATE BETWEEN '" + this.CREATE_DATE_BEGIN.Text + "' AND '" + this.create_date_end.Text + "'),amount=((SELECT DEBIT FROM(SELECT*FROM OPERATIONS WHERE CREATE_DATE BETWEEN '" + this.CREATE_DATE_BEGIN.Text + "' AND '" + this.create_date_end.Text + "' ORDER BY DEBIT) WHERE ROWNUM=1))-(SELECT SUM(CREDIT) FROM OPERATIONS WHERE CREATE_DATE BETWEEN '" + this.CREATE_DATE_BEGIN.Text + "' AND '" + this.create_date_end.Text + "'),CREATE_DATE_BEGIN = '" + this.CREATE_DATE_BEGIN.Text + "',CREATE_DATE_END = '" + this.create_date_end.Text + "' where id='" + this.id.Text + "'";
            OracleConnection con = new OracleConnection(conString);
            OracleCommand cmdDataBase = new OracleCommand(Query, con);
            OracleDataReader myReader;
            try
            {
                con.Open();
                myReader = cmdDataBase.ExecuteReader();
                MessageBox.Show("Баланс изменен");
                while (myReader.Read()) { }
                con.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
