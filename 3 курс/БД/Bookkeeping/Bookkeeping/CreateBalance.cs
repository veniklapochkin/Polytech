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
    public partial class CreateBalance : Form
    {
        string conString = "DATA SOURCE=localhost:1521/orcl;USER ID=VLAD_BORISOV;Password=0000";
        public CreateBalance()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void CreateBalance_Load(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void create_date_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string Query = "INSERT INTO BALANCE(ID,DEBIT,CREDIT,CREATE_DATE_BEGIN,CREATE_DATE_END,AMOUNT) VALUES (BALANCE_SEQ_ID.NEXTVAL,(SELECT DEBIT FROM(SELECT*FROM OPERATIONS WHERE CREATE_DATE BETWEEN '" + this.create_date1.Text + "' AND '" + this.create_date2.Text + "' ORDER BY DEBIT) WHERE ROWNUM=1),(SELECT SUM(CREDIT) FROM OPERATIONS WHERE CREATE_DATE BETWEEN '" + this.create_date1.Text + "' AND '" + this.create_date2.Text + "'),'" + this.create_date1.Text + "','" + this.create_date2.Text + "',((SELECT DEBIT FROM(SELECT*FROM OPERATIONS WHERE CREATE_DATE BETWEEN '" + this.create_date1.Text + "' AND '" + this.create_date2.Text + "' ORDER BY DEBIT) WHERE ROWNUM=1))-(SELECT SUM(CREDIT) FROM OPERATIONS WHERE CREATE_DATE BETWEEN '" + this.create_date1.Text + "' AND '" + this.create_date2.Text + "'))";
            OracleConnection con = new OracleConnection(conString);
            OracleCommand cmdDataBase = new OracleCommand(Query, con);
            OracleDataReader myReader;
            try
            {
                con.Open();
                myReader = cmdDataBase.ExecuteReader();
                MessageBox.Show("Баланс сформирован");
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
