using System;
using System.Collections.Generic;

namespace ColorMapSpace
{
    // ---- 1. Color Data ----
    public static class ColorData
    {
        public static readonly string[] MajorColors = { "White", "Red", "Black", "Yellow", "Violet" };
        public static readonly string[] MinorColors = { "Blue", "Orange", "Green", "Brown", "Slate" };
    }

    // ---- 2. Color Pair Model ----
    public class ColorPair
    {
        public int Number { get; set; }
        public string MajorColor { get; set; }
        public string MinorColor { get; set; }

        public override string ToString()
        {
            return $"{Number} | {MajorColor} | {MinorColor}";
        }
    }

    // ---- 3. Generator ----
    public static class ColorMapGenerator
    {
        public static List<ColorPair> Generate()
        {
            var colorPairs = new List<ColorPair>();
            int pairNumber = 0;

            for (int i = 0; i < ColorData.MajorColors.Length; i++)
            {
                for (int j = 0; j < ColorData.MinorColors.Length; j++)
                {
                    colorPairs.Add(new ColorPair
                    {
                        Number = pairNumber++,
                        MajorColor = ColorData.MajorColors[i],
                        MinorColor = ColorData.MinorColors[j]
                    });
                }
            }

            return colorPairs;
        }
    }

    // ---- 4. Printer ----
    public static class ColorMapPrinter
    {
        public static int Print(List<ColorPair> colorPairs)
        {
            foreach (var pair in colorPairs)
            {
                Console.WriteLine(pair.ToString());
            }

            Console.WriteLine($"Total pairs: {colorPairs.Count}");
            return colorPairs.Count;
        }
    }

    // ---- 5. Main / App Entry ----
    class Program
    {
        static void Main(string[] args)
        {
            var colorPairs = ColorMapGenerator.Generate();
            int total = ColorMapPrinter.Print(colorPairs);
            Console.WriteLine($"Color map printed with total pairs: {total}");
        }
    }
}
