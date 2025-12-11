using Renci.SshNet;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static Org.BouncyCastle.Crypto.Engines.SM2Engine;


namespace Poste_Commandes
{
    public partial class Form1 : Form
    {
        SerialPort serialPort;
        string ImagePath = "U:/A25/Projet Fin de session/Projet-Fin-Session-A25/Code C#/Poste_Commandes/Images/";


        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            switch (ToggleButton.Text)
            {
                case "On":
                    ToggleButton.Text = "Off";
                    break;

                case "Off":
                    ToggleButton.Text = "On";
                    break;
            }
            serialPort.Write(ToggleButton.Text + "\n");

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string Path_To_Image = ImagePath + "Vehicule_Perdu.png";
            serialPort = new SerialPort();
            serialPort.PortName = "COM1";
            serialPort.BaudRate = 19200;
            serialPort.Open();
            serialPort.DiscardInBuffer();
            serialPort.DataReceived += new SerialDataReceivedEventHandler(SerialReception);
            FormClosing += new FormClosingEventHandler(Form_Closing);
            PositionVehiculeImage.Image = Image.FromFile(Path_To_Image);
            CheckPorts();
        }

        private void SerialReception(object sender, SerialDataReceivedEventArgs e)
        {

        }


        private void SendingTimer_Tick(object sender, EventArgs e)
        {
          
        }

        private void Form_Closing(object sender, FormClosingEventArgs e)
        {
            serialPort.Write("Off\n");

            serialPort.Close();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void CheckPorts()
        {
            string[] ports = SerialPort.GetPortNames();
            PortsListe.Items.Clear();
            PortsListe.Items.AddRange(ports);
            try
            {
                PortsListe.SelectedItem = ports[0];
            }
            catch (IndexOutOfRangeException)
            {
                MessageBox.Show("Erreur: Aucun port trouvé");
            }
        }

        private void PortsListe_SelectedIndexChanged(object sender, EventArgs e)
        {
            serialPort.Close();
            if (PortsListe.SelectedItem != null)
            {
                serialPort.PortName = PortsListe.SelectedItem.ToString();
            }
            serialPort.BaudRate = 19200;
            serialPort.Open();
        }

        private void ReceiveTimer_Tick(object sender, EventArgs e)
        {

        }
    }
}


