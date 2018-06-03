using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Runtime.InteropServices;

namespace MyHelloWorld
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        [DllImport(@"D:\ForCSharpCalc.dll", EntryPoint = "Add")]
        private static extern int add(int a, int b);


        [DllImport(@"D:\ForCSharpCalc.dll", EntryPoint = "Substract")]
        private static extern int sub(int a, int b);

        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnAdd_Click(object sender, RoutedEventArgs e)
        {
            tbOutput.Text = string.Format("{0}", add(int.Parse(tbX.Text), int.Parse(tbY.Text)));
        }

        private void btnSub_Click(object sender, RoutedEventArgs e)
        {
            tbOutput.Text = string.Format("{0}", sub(int.Parse(tbX.Text), int.Parse(tbY.Text)));
        }
    }
}
