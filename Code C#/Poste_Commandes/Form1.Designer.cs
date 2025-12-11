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
            PortsListe = new ComboBox();
            GrammeButton = new RadioButton();
            OunceButton = new RadioButton();
            label4 = new Label();
            label5 = new Label();
            PoidPastille = new TextBox();
            PositionVéhicule = new TextBox();
            groupBox1 = new GroupBox();
            groupBox2 = new GroupBox();
            groupBox3 = new GroupBox();
            groupBox4 = new GroupBox();
            PositionVehiculeImage = new PictureBox();
            ReceiveTimer = new System.Windows.Forms.Timer(components);
            SendingTimer = new System.Windows.Forms.Timer(components);
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox3.SuspendLayout();
            groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)PositionVehiculeImage).BeginInit();
            SuspendLayout();
            // 
            // ToggleButton
            // 
            ToggleButton.Location = new Point(23, 35);
            ToggleButton.Name = "ToggleButton";
            ToggleButton.Size = new Size(142, 114);
            ToggleButton.TabIndex = 0;
            ToggleButton.Text = "Off";
            ToggleButton.UseVisualStyleBackColor = true;
            ToggleButton.Click += button1_Click;
            // 
            // PortsListe
            // 
            PortsListe.FormattingEnabled = true;
            PortsListe.Location = new Point(27, 35);
            PortsListe.Name = "PortsListe";
            PortsListe.Size = new Size(121, 23);
            PortsListe.TabIndex = 3;
            PortsListe.SelectedIndexChanged += PortsListe_SelectedIndexChanged;
            // 
            // GrammeButton
            // 
            GrammeButton.AutoSize = true;
            GrammeButton.Location = new Point(50, 96);
            GrammeButton.Name = "GrammeButton";
            GrammeButton.Size = new Size(32, 19);
            GrammeButton.TabIndex = 4;
            GrammeButton.TabStop = true;
            GrammeButton.Text = "g";
            GrammeButton.UseVisualStyleBackColor = true;
            GrammeButton.CheckedChanged += radioButton1_CheckedChanged;
            // 
            // OunceButton
            // 
            OunceButton.AutoSize = true;
            OunceButton.Location = new Point(88, 96);
            OunceButton.Name = "OunceButton";
            OunceButton.Size = new Size(37, 19);
            OunceButton.TabIndex = 5;
            OunceButton.TabStop = true;
            OunceButton.Text = "oz";
            OunceButton.UseVisualStyleBackColor = true;
            OunceButton.CheckedChanged += radioButton1_CheckedChanged;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 14F);
            label4.Location = new Point(23, 19);
            label4.Name = "label4";
            label4.Size = new Size(53, 25);
            label4.TabIndex = 7;
            label4.Text = "Poid:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(6, 96);
            label5.Name = "label5";
            label5.Size = new Size(38, 15);
            label5.TabIndex = 8;
            label5.Text = "Unité:";
            // 
            // PoidPastille
            // 
            PoidPastille.Enabled = false;
            PoidPastille.Location = new Point(23, 67);
            PoidPastille.Name = "PoidPastille";
            PoidPastille.Size = new Size(125, 23);
            PoidPastille.TabIndex = 9;
            // 
            // PositionVéhicule
            // 
            PositionVéhicule.Enabled = false;
            PositionVéhicule.Location = new Point(53, 22);
            PositionVéhicule.Name = "PositionVéhicule";
            PositionVéhicule.Size = new Size(277, 23);
            PositionVéhicule.TabIndex = 10;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(ToggleButton);
            groupBox1.Location = new Point(33, 27);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(261, 195);
            groupBox1.TabIndex = 11;
            groupBox1.TabStop = false;
            groupBox1.Text = "Contrôle de l'usine";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(PortsListe);
            groupBox2.Location = new Point(431, 27);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(251, 127);
            groupBox2.TabIndex = 12;
            groupBox2.TabStop = false;
            groupBox2.Text = "Port Série";
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(PoidPastille);
            groupBox3.Controls.Add(GrammeButton);
            groupBox3.Controls.Add(OunceButton);
            groupBox3.Controls.Add(label5);
            groupBox3.Controls.Add(label4);
            groupBox3.Location = new Point(33, 238);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(286, 170);
            groupBox3.TabIndex = 13;
            groupBox3.TabStop = false;
            groupBox3.Text = "Information du poid";
            // 
            // groupBox4
            // 
            groupBox4.Controls.Add(PositionVehiculeImage);
            groupBox4.Controls.Add(PositionVéhicule);
            groupBox4.Location = new Point(384, 199);
            groupBox4.Name = "groupBox4";
            groupBox4.Size = new Size(404, 224);
            groupBox4.TabIndex = 14;
            groupBox4.TabStop = false;
            groupBox4.Text = "Position du Véhicule";
            // 
            // PositionVehiculeImage
            // 
            PositionVehiculeImage.Location = new Point(16, 58);
            PositionVehiculeImage.Name = "PositionVehiculeImage";
            PositionVehiculeImage.Size = new Size(358, 149);
            PositionVehiculeImage.SizeMode = PictureBoxSizeMode.StretchImage;
            PositionVehiculeImage.TabIndex = 11;
            PositionVehiculeImage.TabStop = false;
            // 
            // ReceiveTimer
            // 
            ReceiveTimer.Interval = 500;
            ReceiveTimer.Tick += ReceiveTimer_Tick;
            // 
            // SendingTimer
            // 
            SendingTimer.Enabled = true;
            SendingTimer.Interval = 500;
            SendingTimer.Tick += SendingTimer_Tick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(groupBox4);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Name = "Form1";
            Text = " ";
            Load += Form1_Load;
            groupBox1.ResumeLayout(false);
            groupBox2.ResumeLayout(false);
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            groupBox4.ResumeLayout(false);
            groupBox4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)PositionVehiculeImage).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private Button ToggleButton;
        private ComboBox PortsListe;
        private RadioButton GrammeButton;
        private RadioButton OunceButton;
        private Label label4;
        private Label label5;
        private TextBox PoidPastille;
        private TextBox PositionVéhicule;
        private GroupBox groupBox1;
        private GroupBox groupBox2;
        private GroupBox groupBox3;
        private GroupBox groupBox4;
        private PictureBox PositionVehiculeImage;
        private System.Windows.Forms.Timer ReceiveTimer;
        private System.Windows.Forms.Timer SendingTimer;
    }
}
