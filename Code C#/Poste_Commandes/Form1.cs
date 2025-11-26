using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Renci.SshNet;


namespace Poste_Commandes
{
    public partial class Form1 : Form
    {
        SerialPort serialPort;
        SerialDataReceivedEventHandler serialDataReceived;


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


        }

        private void Form1_Load(object sender, EventArgs e)
        {
            serialPort = new SerialPort();
            serialPort.PortName = "COM20";
            serialPort.BaudRate = 19200;
            serialPort.Open();
            serialPort.DiscardInBuffer();
            serialPort.DataReceived += new SerialDataReceivedEventHandler(serialDataReceived);
            FormClosing += new FormClosingEventHandler(Form_Closing);
            CheckPorts();
        }

        private void SendingTimer_Tick(object sender, EventArgs e)
        {
            serialPort.Write(ToggleButton.Text + "\n");
        }

        private void Form_Closing(object sender, FormClosingEventArgs e)
        {
            serialPort.Write("12345ABCDE\n");
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
    }
}


