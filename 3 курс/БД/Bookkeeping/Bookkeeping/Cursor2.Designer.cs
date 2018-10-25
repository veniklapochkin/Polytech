namespace Bookkeeping
{
    partial class Cursor2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.id_third_article = new System.Windows.Forms.TextBox();
            this.id_second_article = new System.Windows.Forms.TextBox();
            this.id_first_article = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.create_date_end = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.create_date_begin = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(147, 322);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 55;
            this.button2.Text = "Cancel";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(237, 322);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 54;
            this.button1.Text = "Run";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(90, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(178, 25);
            this.label1.TabIndex = 53;
            this.label1.Text = "Заполните поля";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // id_third_article
            // 
            this.id_third_article.Location = new System.Drawing.Point(163, 237);
            this.id_third_article.Name = "id_third_article";
            this.id_third_article.Size = new System.Drawing.Size(149, 20);
            this.id_third_article.TabIndex = 67;
            // 
            // id_second_article
            // 
            this.id_second_article.Location = new System.Drawing.Point(163, 200);
            this.id_second_article.Name = "id_second_article";
            this.id_second_article.Size = new System.Drawing.Size(149, 20);
            this.id_second_article.TabIndex = 66;
            // 
            // id_first_article
            // 
            this.id_first_article.Location = new System.Drawing.Point(163, 162);
            this.id_first_article.Name = "id_first_article";
            this.id_first_article.Size = new System.Drawing.Size(149, 20);
            this.id_first_article.TabIndex = 65;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(23, 244);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(112, 13);
            this.label5.TabIndex = 64;
            this.label5.Text = "ID_THIRD_ARTICLE:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(23, 203);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(123, 13);
            this.label4.TabIndex = 63;
            this.label4.Text = "ID_SECOND_ARTICLE:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 162);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(109, 13);
            this.label2.TabIndex = 62;
            this.label2.Text = "ID_FIRST_ARTICLE:";
            // 
            // create_date_end
            // 
            this.create_date_end.Location = new System.Drawing.Point(163, 119);
            this.create_date_end.Name = "create_date_end";
            this.create_date_end.Size = new System.Drawing.Size(149, 20);
            this.create_date_end.TabIndex = 61;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 119);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(117, 13);
            this.label3.TabIndex = 60;
            this.label3.Text = "CREATE_DATE_END:";
            // 
            // create_date_begin
            // 
            this.create_date_begin.Location = new System.Drawing.Point(163, 72);
            this.create_date_begin.Name = "create_date_begin";
            this.create_date_begin.Size = new System.Drawing.Size(149, 20);
            this.create_date_begin.TabIndex = 59;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(23, 72);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(127, 13);
            this.label6.TabIndex = 58;
            this.label6.Text = "CREATE_DATE_BEGIN:";
            // 
            // Cursor2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(334, 361);
            this.Controls.Add(this.id_third_article);
            this.Controls.Add(this.id_second_article);
            this.Controls.Add(this.id_first_article);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.create_date_end);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.create_date_begin);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Name = "Cursor2";
            this.Text = "Cursor2";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox id_third_article;
        private System.Windows.Forms.TextBox id_second_article;
        private System.Windows.Forms.TextBox id_first_article;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox create_date_end;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox create_date_begin;
        private System.Windows.Forms.Label label6;
    }
}