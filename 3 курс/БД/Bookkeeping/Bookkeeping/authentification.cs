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
    public partial class authentification : Form
    {
        string conString = "DATA SOURCE=localhost:1521/orcl;USER ID=VLAD_BORISOV;Password=0000";
        DataTable dbdataset;
        public authentification()
        {
            InitializeComponent();
        }

        private void фыв_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            
            this.Hide();
            MainWindow mw = new MainWindow();
            mw.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //string Query = "Select*from admin";
            string Query = "Select Count(*) from admin where login='" + textBox1.Text + "' and password='" + textBox2.Text + "'";
            OracleConnection con = new OracleConnection(conString);
            OracleCommand cmdDataBase = new OracleCommand(Query,con);
            OracleDataAdapter sda = new OracleDataAdapter();
            sda.SelectCommand = cmdDataBase;
            dbdataset = new DataTable();
            sda.Fill(dbdataset);
            if (textBox1.Text == "" && textBox2.Text == "") {
                MessageBox.Show("Login or password is null");
            }
            else if (textBox1.Text == "")
            {
                MessageBox.Show("Login is null");
            }
            else if (textBox2.Text == "")
            {
                MessageBox.Show("Password is null");
            }
            else if (dbdataset.Rows[0][0].ToString() == "1")
            {
                MessageBox.Show("Hello,"+textBox1.Text);
                this.Hide();
                AdminPage ap = new AdminPage();
                ap.Show();
            }
            else MessageBox.Show("Please check login and password!");
            /*
            try
            {
                OracleDataAdapter sda = new OracleDataAdapter();
                sda.SelectCommand = cmdDataBase;
                dbdataset = new DataTable();
                sda.Fill(dbdataset);
                BindingSource bSource = new BindingSource();
                bSource.DataSource = dbdataset;
                dataGridView1.DataSource = bSource;
                sda.Update(dbdataset);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }*/

        }

    }
}
