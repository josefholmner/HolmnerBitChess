using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HolmnerBitChess_c_generator
{
    public static class HexBinaryHandler
    {
    

        public static string bit4ToHex(string bits4)
        {
            double val = 0;

            for(int i = 3; i >= 0; i--)
            {
                int indexVal;
                int.TryParse(bits4.Substring(i, 1), out indexVal);
                val += indexVal * Math.Pow(2, (3 - i));
            }
            return decimalDigitToHex((int)val);
        }

        public static string bitPatternToHex(int[,] bits)
        {
            string hexValue = "0x";

            for(int i = 0; i < 8; i++)
            {
                for(int j = 1; j >= 0; j--)
                {
                    hexValue += bit4ToHex(bits[j * 4+3, i].ToString() + bits[j * 4 + 2, i].ToString() + bits[j * 4 + 1,i].ToString() + bits[j * 4 + 0,i].ToString());
                }
            }

            return hexValue;
        }
        

        private static string decimalDigitToHex(int digit)
        {
            if (digit < 10)
            {
                return digit.ToString();
            }

            switch (digit)
            {
                case 10:
                    return "A";
                case 11:
                    return "B";
                case 12:
                    return "C";
                case 13:
                    return "D";
                case 14:
                    return "E";
                case 15:
                    return "F";
                default:
                    throw new Exception();
            }

        }

    }
}
