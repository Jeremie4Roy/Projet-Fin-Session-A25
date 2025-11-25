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
            comboBox1 = new ComboBox();
            radioButton1 = new RadioButton();
            radioButton2 = new RadioButton();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            PoidPastille = new TextBox();
            PositionVéhicule = new TextBox();
            SuspendLayout();
            // 
            // ToggleButton
            // 
            ToggleButton.Location = new Point(51, 76);
            ToggleButton.Name = "ToggleButton";
            ToggleButton.Size = new Size(275, 114);
            ToggleButton.TabIndex = 0;
            ToggleButton.Text = "On";
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
            label1.Location = new Point(75, 34);
            label1.Name = "label1";
            label1.Size = new Size(174, 25);
            label1.TabIndex = 1;
            label1.Text = "Contrôle de l'usine:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 14F);
            label2.Location = new Point(483, 44);
            label2.Name = "label2";
            label2.Size = new Size(152, 25);
            label2.TabIndex = 2;
            label2.Text = "Connexion série:";
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(497, 96);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(121, 23);
            comboBox1.TabIndex = 3;
            // 
            // radioButton1
            // 
            radioButton1.AutoSize = true;
            radioButton1.Location = new Point(65, 373);
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
            radioButton2.Location = new Point(103, 373);
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
            label3.Location = new Point(453, 289);
            label3.Name = "label3";
            label3.Size = new Size(88, 25);
            label3.TabIndex = 6;
            label3.Text = "Véhicule:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 14F);
            label4.Location = new Point(37, 289);
            label4.Name = "label4";
            label4.Size = new Size(53, 25);
            label4.TabIndex = 7;
            label4.Text = "Poid:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(21, 377);
            label5.Name = "label5";
            label5.Size = new Size(38, 15);
            label5.TabIndex = 8;
            label5.Text = "Unité:";
            // 
            // PoidPastille
            // 
            PoidPastille.Enabled = false;
            PoidPastille.Location = new Point(37, 329);
            PoidPastille.Name = "PoidPastille";
            PoidPastille.Size = new Size(125, 23);
            PoidPastille.TabIndex = 9;
            // 
            // PositionVéhicule
            // 
            PositionVéhicule.Enabled = false;
            PositionVéhicule.Location = new Point(413, 329);
            PositionVéhicule.Name = "PositionVéhicule";
            PositionVéhicule.Size = new Size(277, 23);
            PositionVéhicule.TabIndex = 10;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(PositionVéhicule);
            Controls.Add(PoidPastille);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(radioButton2);
            Controls.Add(radioButton1);
            Controls.Add(comboBox1);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(ToggleButton);
            Name = "Form1";
            Text = " ";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button ToggleButton;
        private System.Windows.Forms.Timer SendingTimer;
        private Label label1;
        private Label label2;
        private ComboBox comboBox1;
        private RadioButton radioButton1;
        private RadioButton radioButton2;
        private Label label3;
        private Label label4;
        private Label label5;
        private TextBox PoidPastille;
        private TextBox PositionVéhicule;
    }
}
