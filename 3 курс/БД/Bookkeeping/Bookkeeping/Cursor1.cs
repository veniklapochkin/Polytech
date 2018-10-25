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
using System.IO;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
namespace Bookkeeping
{
    public partial class Cursor1 : Form
    {
        string conString = "DATA SOURCE=localhost:1521/orcl;USER ID=VLAD_BORISOV;Password=0000";
        DataTable dbdataset;
        public Cursor1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
        }
        
        private void button1_Click(object sender, EventArgs e)
        {
            string Query = "SELECT article_id,ROUND(debit/(((SELECT SUM(debit) FROM OPERATIONS where CREATE_DATE between '" + this.create_date_begin.Text + "' and '" + this.create_date_end.Text + "' and (ARTICLE_ID='" + this.id_first_article.Text + "' or ARTICLE_ID='" + this.id_second_article.Text + "' or ARTICLE_ID='" + this.id_third_article.Text + "'))))*100,2) as pdebit,ROUND(credit/(((SELECT SUM(credit) FROM OPERATIONS where CREATE_DATE between '" + this.create_date_begin.Text + "' and '" + this.create_date_end.Text + "' and (ARTICLE_ID='" + this.id_first_article.Text + "' or ARTICLE_ID='" + this.id_second_article.Text + "' or ARTICLE_ID='" + this.id_third_article.Text + "'))))*100,2) as pcredit,ROUND((debit-credit)/(((SELECT SUM(debit-CREDIT) FROM OPERATIONS where CREATE_DATE between '" + this.create_date_begin.Text + "' and '" + this.create_date_end.Text + "' and (ARTICLE_ID='" + this.id_first_article.Text + "' or ARTICLE_ID='" + this.id_second_article.Text + "' or ARTICLE_ID='" + this.id_third_article.Text + "'))))*100,2) as pcreditdebit FROM OPERATIONS where ARTICLE_ID='" + this.id_first_article.Text + "' or ARTICLE_ID='" + this.id_second_article.Text + "' or ARTICLE_ID='" + this.id_third_article.Text + "'";
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
    }
}
