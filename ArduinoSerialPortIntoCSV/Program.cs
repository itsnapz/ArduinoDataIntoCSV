using System.IO.Ports;
using System.Text;
using System.Linq;

var csv = new StringBuilder();

List<string> daticka = new List<string>();
Console.WriteLine("Zadejte počet opakování:");
int repeats = int.Parse(Console.ReadLine());

SerialPort _sp = new SerialPort("COM5", 9600, Parity.None, 8, StopBits.One);
_sp.Handshake = Handshake.None;
_sp.Open();

using (var w = new StreamWriter("Data.csv"))
{
    for (int i = 0; i < repeats; i++)
    {
        string data = _sp.ReadLine();
        string datum = DateTime.Now.ToString();
        var line = string.Format("{0}, {1}", datum, data);
        w.WriteLine(line);
    }
    w.Flush();
}



