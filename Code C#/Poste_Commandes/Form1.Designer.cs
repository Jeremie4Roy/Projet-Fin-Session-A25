namespace Poste_Commandes
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            ToggleButton = new Button();
            SendingTimer = new System.Windows.Forms.Timer(components);
            label1 = new Label();
            label2 = new Label();
            PortsListe = new ComboBox();
            radioButton1 = new RadioButton();
            radioButton2 = new RadioButton();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            PoidPastille = new TextBox();
            PositionVéhicule = new TextBox();
            groupBox1 = new GroupBox();
            groupBox2 = new GroupBox();
            groupBox3 = new GroupBox();
            groupBox4 = new GroupBox();
            PositionVehiculeImage = new PictureBox();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox3.SuspendLayout();
            groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)PositionVehiculeImage).BeginInit();
            SuspendLayout();
            // 
            // ToggleButton
            // 
            ToggleButton.Location = new Point(28, 69);
            ToggleButton.Name = "ToggleButton";
            ToggleButton.Size = new Size(142, 114);
            ToggleButton.TabIndex = 0;
            ToggleButton.Text = "Off";
            ToggleButton.UseVisualStyleBackColor = true;
            ToggleButton.Click += button1_Click;
            // 
            // SendingTimer
            // 
            SendingTimer.Enabled = true;
            SendingTimer.Interval = 1000;
            SendingTimer.Tick += SendingTimer_Tick;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 14F);
            label1.Location = new Point(14, 17);
            label1.Name = "label1";
            label1.Size = new Size(174, 25);
            label1.TabIndex = 1;
            label1.Text = "Contrôle de l'usine:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 14F);
            label2.Location = new Point(6, 19);
            label2.Name = "label2";
            label2.Size = new Size(152, 25);
            label2.TabIndex = 2;
            label2.Text = "Connexion série:";
            // 
            // PortsListe
            // 
            PortsListe.FormattingEnabled = true;
<<<<<<< HEAD
            PortsListe.Location = new Point(6, 69);
=======
            PortsListe.Location = new Point(497, 96);
>>>>>>> 56a8191b17922e0ffaa4cec6e380f782907ddd16
            PortsListe.Name = "PortsListe";
            PortsListe.Size = new Size(121, 23);
            PortsListe.TabIndex = 3;
            PortsListe.SelectedIndexChanged += PortsListe_SelectedIndexChanged;
            // 
            // radioButton1
            // 
            radioButton1.AutoSize = true;
            radioButton1.Location = new Point(54, 127);
            radioButton1.Name = "radioButton1";
            radioButton1.Size = new Size(32, 19);
            radioButton1.TabIndex = 4;
            radioButton1.TabStop = true;
            radioButton1.Text = "g";
            radioButton1.UseVisualStyleBackColor = true;
            radioButton1.CheckedChanged += radioButton1_CheckedChanged;
            // 
            // radioButton2
            // 
            radioButton2.AutoSize = true;
            radioButton2.Location = new Point(92, 127);
            radioButton2.Name = "radioButton2";
            radioButton2.Size = new Size(37, 19);
            radioButton2.TabIndex = 5;
            radioButton2.TabStop = true;
            radioButton2.Text = "oz";
            radioButton2.UseVisualStyleBackColor = true;
            radioButton2.CheckedChanged += radioButton1_CheckedChanged;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 14F);
            label3.Location = new Point(39, 19);
            label3.Name = "label3";
            label3.Size = new Size(88, 25);
            label3.TabIndex = 6;
            label3.Text = "Véhicule:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 14F);
            label4.Location = new Point(26, 43);
            label4.Name = "label4";
            label4.Size = new Size(53, 25);
            label4.TabIndex = 7;
            label4.Text = "Poid:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(10, 131);
            label5.Name = "label5";
            label5.Size = new Size(38, 15);
            label5.TabIndex = 8;
            label5.Text = "Unité:";
            // 
            // PoidPastille
            // 
            PoidPastille.Enabled = false;
            PoidPastille.Location = new Point(26, 83);
            PoidPastille.Name = "PoidPastille";
            PoidPastille.Size = new Size(125, 23);
            PoidPastille.TabIndex = 9;
            // 
            // PositionVéhicule
            // 
            PositionVéhicule.Enabled = false;
            PositionVéhicule.Location = new Point(15, 68);
            PositionVéhicule.Name = "PositionVéhicule";
            PositionVéhicule.Size = new Size(277, 23);
            PositionVéhicule.TabIndex = 10;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(label1);
            groupBox1.Controls.Add(ToggleButton);
            groupBox1.Location = new Point(37, 27);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(311, 195);
            groupBox1.TabIndex = 11;
            groupBox1.TabStop = false;
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(PortsListe);
            groupBox2.Controls.Add(label2);
            groupBox2.Location = new Point(461, 27);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(181, 105);
            groupBox2.TabIndex = 12;
            groupBox2.TabStop = false;
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(PoidPastille);
            groupBox3.Controls.Add(label5);
            groupBox3.Controls.Add(label4);
            groupBox3.Controls.Add(radioButton2);
            groupBox3.Controls.Add(radioButton1);
            groupBox3.Location = new Point(27, 244);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(286, 170);
            groupBox3.TabIndex = 13;
            groupBox3.TabStop = false;
            // 
            // groupBox4
            // 
            groupBox4.Controls.Add(PositionVehiculeImage);
            groupBox4.Controls.Add(PositionVéhicule);
            groupBox4.Controls.Add(label3);
            groupBox4.Location = new Point(384, 151);
            groupBox4.Name = "groupBox4";
            groupBox4.Size = new Size(404, 263);
            groupBox4.TabIndex = 14;
            groupBox4.TabStop = false;
            // 
            // PositionVehiculeImage
            // 
            PositionVehiculeImage.Location = new Point(15, 108);
            PositionVehiculeImage.Name = "PositionVehiculeImage";
            PositionVehiculeImage.Size = new Size(358, 149);
            PositionVehiculeImage.SizeMode = PictureBoxSizeMode.StretchImage;
            PositionVehiculeImage.TabIndex = 11;
            PositionVehiculeImage.TabStop = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
<<<<<<< HEAD
            Controls.Add(groupBox4);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
=======
            Controls.Add(PositionVéhicule);
            Controls.Add(PoidPastille);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(radioButton2);
            Controls.Add(radioButton1);
            Controls.Add(PortsListe);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(ToggleButton);
>>>>>>> 56a8191b17922e0ffaa4cec6e380f782907ddd16
            Name = "Form1";
            Text = " ";
            Load += Form1_Load;
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            groupBox4.ResumeLayout(false);
            groupBox4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)PositionVehiculeImage).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private Button ToggleButton;
        private System.Windows.Forms.Timer SendingTimer;
        private Label label1;
        private Label label2;
        private ComboBox PortsListe;
        private RadioButton radioButton1;
        private RadioButton radioButton2;
        private Label label3;
        private Label label4;
        private Label label5;
        private TextBox PoidPastille;
        private TextBox PositionVéhicule;
        private GroupBox groupBox1;
        private GroupBox groupBox2;
        private GroupBox groupBox3;
        private GroupBox groupBox4;
        private PictureBox PositionVehiculeImage;
    }
}
