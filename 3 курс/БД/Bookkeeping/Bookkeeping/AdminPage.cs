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
//using System.Data.OracleClient;
namespace Bookkeeping
{
    public partial class AdminPage : Form
    {
        string conString = "DATA SOURCE=localhost:1521/orcl;USER ID=VLAD_BORISOV;Password=0000";
        DataTable dbdataset;
        
        public AdminPage()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string Query = "Select * from Articles";
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
                dataGridView1.DataSource = bSource;
                sda.Update(dbdataset);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            string Query = "Select * from Operations";
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
                dataGridView1.DataSource = bSource;
                sda.Update(dbdataset);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Hide();
            authentification aut = new authentification();
            aut.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string Query = "Select * from Balance";
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
                dataGridView1.DataSource = bSource;
                sda.Update(dbdataset);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.Text.Contains("a)")) {
                string Query = "SELECT * FROM OPERATIONS WHERE (CREATE_DATE BETWEEN '01-01-2016' and '31-01-2016')";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }   
            }
            else if (comboBox1.Text.Contains("b)"))
            {
                string Query = "SELECT * FROM OPERATIONS WHERE (CREATE_DATE BETWEEN '01-02-2016' and '29-02-2016')";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("c)"))
            {
                string Query = "SELECT * FROM ARTICLES ORDER BY NAME";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("d)"))
            {
                string Query = "SELECT * FROM OPERATIONS ORDER BY CREATE_DATE DESC,DEBIT";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("e)"))
            {
                string Query = "SELECT * FROM ARTICLES WHERE NAME LIKE '%Оплатил%' OR NAME LIKE '%оплатил%'";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("f)"))
            {
                string Query = "SELECT AMOUNT FROM BALANCE where create_date_begin =  '01.01.16' and create_date_end='30.01.16'";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("g)"))
            {
                string Query = "SELECT AMOUNT FROM BALANCE where create_date_begin='01.02.16' and create_date_end='28.02.16'";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("h)"))
            {
                string Query = "SELECT Credit FROM BALANCE where create_date_begin='01.01.16' and create_date_end='30.01.16'";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("i)"))
            {
                string Query = "SELECT Credit FROM BALANCE where create_date_begin='01.02.16' and create_date_end='28.02.16'";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("j)"))
            {
                string Query = "SELECT*FROM OPERATIONS WHERE BALANCE_ID IN(SELECT ID FROM BALANCE)";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("k)"))
            {
                string Query = "SELECT NAME FROM ARTICLES WHERE not exists(SELECT ARTICLE_ID FROM OPERATIONS WHERE CREATE_DATE between '01-01-2016' and '28-02-2016')";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("l)"))
            {
                string Query = "SELECT COUNT(NAME) FROM ARTICLES WHERE not exists(SELECT ARTICLE_ID FROM OPERATIONS WHERE CREATE_DATE between '01-01-2016' and '28-02-2016')";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else if (comboBox1.Text.Contains("m)"))
            {
                string Query = "SELECT * FROM OPERATIONS full JOIN ARTICLES ON OPERATIONS.ID = ARTICLES.ID";
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
                    dataGridView1.DataSource = bSource;
                    sda.Update(dbdataset);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //this.Hide();
            AddArticle aa = new AddArticle();
            aa.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            //this.Hide();
            AddOperation ao = new AddOperation();
            ao.Show();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            //this.Hide();
            CreateBalance cb = new CreateBalance();
            cb.Show();
        }

        private void AdminPage_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {
            DeleteArticle da = new DeleteArticle();
            da.Show();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            ChangeArticle ca = new ChangeArticle();
            ca.Show();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            DeleteOperation dop = new DeleteOperation();
            dop.Show();

        }

        private void button10_Click(object sender, EventArgs e)
        {
            ChangeOperations co = new ChangeOperations();
            co.Show();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            DeleteBalance db = new DeleteBalance();
            db.Show();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            ChangeBalance cb = new ChangeBalance();
            cb.Show();
        }

        private void button14_Click(object sender, EventArgs e)
        {
            Cursor1 c1 = new Cursor1();
            c1.Show();
        }

        private void button15_Click(object sender, EventArgs e)
        {
            Cursor2 c2 = new Cursor2();
            c2.Show();

            /*string Query = "SELECT article_id,(((SELECT ROUND(1/count(debit),2) FROM OPERATIONS where CREATE_DATE between '01.01.2016' and '10.01.2016' and ARTICLE_ID=5 or ARTICLE_ID=9 or ARTICLE_ID=7)))*100 as pdebit,(((SELECT ROUND(1/count(credit),2) FROM OPERATIONS where CREATE_DATE between '01.01.2016' and '10.01.2016' and ARTICLE_ID=5 or ARTICLE_ID=9 or ARTICLE_ID=7)))*100 as pcredit,(((SELECT ROUND(1/count(debit-CREDIT),2) FROM OPERATIONS where CREATE_DATE between '01.01.2016' and '10.01.2016' and ARTICLE_ID=5 or ARTICLE_ID=9 or ARTICLE_ID=7)))*100 as pcreditdebit FROM OPERATIONS where ARTICLE_ID=5 or ARTICLE_ID=9 or ARTICLE_ID=7";
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
