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
    
    public partial class Cursor2 : Form
    {
        string conString = "DATA SOURCE=localhost:1521/orcl;USER ID=VLAD_BORISOV;Password=0000";
        DataTable dbdataset;
        public Cursor2()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            string Query = "SELECT article_id,(((SELECT ROUND(1/count(debit),2) FROM OPERATIONS where CREATE_DATE between '" + this.create_date_begin.Text + "' and '" + this.create_date_end.Text + "' and (ARTICLE_ID='" + this.id_first_article.Text + "' or ARTICLE_ID='" + this.id_second_article.Text + "' or ARTICLE_ID='" + this.id_third_article.Text + "'))))*100 as pdebit,(((SELECT ROUND(1/count(credit),2) FROM OPERATIONS where CREATE_DATE between '" + this.create_date_begin.Text + "' and '" + this.create_date_end.Text + "' and (ARTICLE_ID='" + this.id_first_article.Text + "' or ARTICLE_ID='" + this.id_second_article.Text + "' or ARTICLE_ID='" + this.id_third_article.Text + "'))))*100 as pcredit,(((SELECT ROUND(1/count(debit-CREDIT),2) FROM OPERATIONS where CREATE_DATE between '" + this.create_date_begin.Text + "' and '" + this.create_date_end.Text + "' and (ARTICLE_ID='" + this.id_first_article.Text + "' or ARTICLE_ID='" + this.id_second_article.Text + "' or ARTICLE_ID='" + this.id_third_article.Text + "'))))*100 as pcreditdebit FROM OPERATIONS where ARTICLE_ID='" + this.id_first_article.Text + "' or ARTICLE_ID='" + this.id_second_article.Text + "' or ARTICLE_ID='" + this.id_third_article.Text + "'";
            OracleConnection con = new OracleConnection(conString);
            OracleCommand cmdDataBase = new OracleCommand(Query, con);
            try
            {
                OracleDataAdapter sda = new OracleDataAdapter();
                sda.SelectCommand = cmdDataBase;
                dbdataset = new DataTable();
                sda.Fill(dbdataset);
                BindingSource bSource = new BindingSource();
                bSource.DataSource = dbdataset;
                AdminPage ap = new AdminPage();
                ap.dataGridView1.DataSource = bSource;
                sda.Update(dbdataset);
                ap.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
