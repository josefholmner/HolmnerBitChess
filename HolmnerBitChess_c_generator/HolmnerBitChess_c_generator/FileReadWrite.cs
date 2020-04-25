using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HolmnerBitChess_c_generator
{
    static class FileReadWrite
    {
        public static void readAndAppend(string inputFile, string outputFile, string sq, int prefixTabs = 0, string replace_this = "", string replace_with = "")
        {
            string line = "";
            System.IO.StreamReader file_in = new System.IO.StreamReader(inputFile);
            System.IO.StreamWriter file_out = System.IO.File.AppendText(outputFile);
            while ((line = file_in.ReadLine()) != null)
            {
                if(line.Contains("_sq_"))
                {
                    line = line.Replace("_sq_", sq);                    
                }

                string tab = "";
                for (int i = 0; i < prefixTabs; i++)
                {
                    tab += "\t";
                }

                if (replace_this != "" && line.Contains(replace_this))
                {
                    line = line.Replace(replace_this, replace_with);
                }

                file_out.WriteLine(tab + line);
            }

            file_in.Close();
            file_out.Close();
        }

        public static void writeToFile(string filePath, string message, int prefixTabs = 0)
        {
            System.IO.StreamWriter file_out = System.IO.File.AppendText(filePath);
            string tab = "";
            for(int i = 0; i < prefixTabs; i++)
            {
                tab += "\t";
            }
            file_out.WriteLine(tab + message);
            file_out.Close();
        }

        public static void readAndAppend_twoSq(string inputFile, string outputFile, string sq, string sq2)
        {
            string line = "";
            System.IO.StreamReader file_in = new System.IO.StreamReader(inputFile);
            System.IO.StreamWriter file_out = System.IO.File.AppendText(outputFile);
            while ((line = file_in.ReadLine()) != null)
            {
                if (line.Contains("_sq_"))
                {
                    line = line.Replace("_sq_", sq);
                }
                if (line.Contains("_sq2_"))
                {
                    line = line.Replace("_sq2_", sq2);
                }

                file_out.WriteLine(line);
            }

            file_in.Close();
            file_out.Close();
        }
    }
}
