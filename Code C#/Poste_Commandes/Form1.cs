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
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form_Closing);
        }

        private void SendingTimer_Tick(object sender, EventArgs e)
        {
            serialPort.Write(ToggleButton.Text + "\n");
        }

        private void Form_Closing(object sender, FormClosingEventArgs e)
        {
            serialPort.Write("12345ABCDE\n");//The Kill Code :)
            serialPort.Close();
        }
    }
}
