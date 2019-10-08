/// <summary>
/// 我的方案
/// 种群数量100
/// 轮盘赌选择
/// 随机单点交叉 0.6概率
/// 均匀变异 0.002概率
/// </summary>
namespace BinaryGeneticAlgorithms.rainingYao
{
    using NUnit.Framework;
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;

    // TODO: Replace examples and use TDD development by writing your own tests

    [TestFixture]
    public class SolutionTest
    {
        static string ideal = "1001100110011001";
        GeneticAlgorithm genetic = new GeneticAlgorithm();

        [Test]
        public void Len4For100Test()
        {
            ideal = genetic.Generate(4);
            Assert.AreEqual(ideal, genetic.Run(fitness, ideal.Length, 0.6, 0.002, 100));
        }

        [Test]
        public void Len35For1000Test()
        {
            ideal = genetic.Generate(35);
            Assert.AreEqual(ideal, genetic.Run(fitness, ideal.Length, 0.6, 0.002, 1000));
        }

        public readonly Func<string, double> fitness = (c) =>
        {
            if (c.Length != ideal.Length) return 0;
            int i = 0, count = new int[c.Length].Count(_ => ideal[i] != c[i++]);
            return 1d / (count + 1);
        };
    }

    public class GeneticAlgorithm
    {
        private Random random = new Random();

        public string Generate(int length)
        {
            return string.Concat(new int[length].Select(i => random.Next(2)));
        }

        public string Select(IEnumerable<string> population, IEnumerable<double> fitnesses, double sum = 0)
        {
            double surviving = random.NextDouble() * sum;
            int i = 0;
            while (surviving > 0) surviving -= fitnesses.ElementAt(i++);
            return population.ElementAt(--i);
        }

        public string Mutate(string chromosome, double probability)
        {
            return string.Concat(chromosome.Select(c => random.NextDouble() >= probability ? c : c == '1' ? '0' : '1'));
        }

        public IEnumerable<string> Crossover(string chromosome1, string chromosome2)
        {
            int cut = random.Next(chromosome1.Length, chromosome1.Length);
            return new string[] { chromosome1.Substring(0, cut) + chromosome2.Substring(cut),
            chromosome2.Substring(0, cut) + chromosome1.Substring(cut)};
        }

        public string Run(Func<string, double> fitness, int length, double p_c, double p_m, int iterations = 100)
        {
            int count = 50 * 2;
            string[] population = new string[count];
            double[] fitnesses = new double[count];
            for (int i = 0; i < count; i++)
            {
                string chromosome = Generate(length);
                population[i] = chromosome;
                fitnesses[i] = fitness(chromosome);
            }
            for (int i = 0; i < iterations; i++)
            {
                //if (fitnesses.Max() == 1) break;
                string[] sons = new string[count];
                double[] sonsfitnesses = new double[count];
                for (int j = 0; j < count / 2; j++)
                {
                    string p = Select(population, fitnesses, fitnesses.Sum());
                    string q = Select(population, fitnesses, fitnesses.Sum());
                    if (random.NextDouble() <= p_c)
                    {
                        int cut = random.Next(0, length);
                        (p, q) = (p.Substring(0, cut) + q.Substring(cut), q.Substring(0, cut) + p.Substring(cut));
                    }
                    q = Mutate(q, p_m); p = Mutate(p, p_m);
                    sons[j] = q;
                    sons[j + count / 2] = p;
                    sonsfitnesses[j] = fitness(q);
                    sonsfitnesses[j + count / 2] = fitness(p);
                }
                sons.CopyTo(population, 0);
                sonsfitnesses.CopyTo(fitnesses, 0);
            }
            return population[Array.IndexOf(fitnesses, fitnesses.Max())];
        }
    }

    [TestFixture]
    public class KataTest
    {
        private GeneticAlgorithm GA = new GeneticAlgorithm();
        private const int CL = 35;
        private Random random = new Random();

        [Test]
        public void _0_SmallTests()
        {
            StringBuilder sb;
            string goal;
            Func<string, double> f;
            int size = 4;

            for (int i = 0; i < 2; ++i)
            {
                sb = new StringBuilder(size);

                for (int j = 0; j < size; ++j)
                {
                    sb.Append(Math.Floor(2 * random.NextDouble()).ToString());
                }
                goal = sb.ToString();
                f = Fitness(goal);

                Assert.AreEqual(goal, GA.Run(f, size, 0.6, 0.002));
            }
        }

        [Test]
        public void _1_GeneticAlgorithm()
        {
            StringBuilder sb = new StringBuilder(CL);
            string goal;
            Func<string, double> f;

            for (int j = 0; j < CL; ++j)
            {
                sb.Append(Math.Floor(2 * random.NextDouble()).ToString());
            }
            goal = sb.ToString();
            f = Fitness(goal);

            Assert.AreEqual(goal, GA.Run(f, CL, 0.6, 0.002));
        }

        Func<string, double> Fitness(string goal)
        {
            return (c) =>
            {
                if (c.Length != goal.Length) return 0;
                int i = 0, count = new int[c.Length].Count(_ => goal[i] != c[i++]);
                return 1d / (count + 1);
            };
        }
    }
}

/// <summary>
/// 用户名wojtix144
/// 种群数量100
/// 最佳保留选择（非轮盘赌）
/// 均匀交叉 0.5概率
/// 无变异
/// </summary>
namespace BinaryGeneticAlgorithms.wojtix144
{
    using NUnit.Framework;
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;

    // TODO: Replace examples and use TDD development by writing your own tests

    [TestFixture]
    public class SolutionTest
    {
        static string ideal = "1001100110011001";
        GeneticAlgorithm genetic = new GeneticAlgorithm();

        [Test]
        public void Len4For100Test()
        {
            ideal = genetic.Generate(4);
            Assert.AreEqual(ideal, genetic.Run(fitness, ideal.Length, 0.6, 0.002, 100));
        }

        [Test]
        public void Len35For1000Test()
        {
            ideal = genetic.Generate(35);
            Assert.AreEqual(ideal, genetic.Run(fitness, ideal.Length, 0.6, 0.002, 1000));
        }

        public readonly Func<string, double> fitness = (c) =>
        {
            if (c.Length != ideal.Length) return 0;
            int i = 0, count = new int[c.Length].Count(_ => ideal[i] != c[i++]);
            return 1d / (count + 1);
        };
    }

    public class GeneticAlgorithm
    {
        private Random random = new Random();

        public string Generate(int length)
        {
            var chromosome = new char[length];
            for (int i = 0; i < length; i++)
            {
                chromosome[i] = Convert.ToChar(random.Next(2).ToString());
            }
            return new string(chromosome);
        }

        public string Select(IEnumerable<string> population, IEnumerable<double> fitnesses, double sum = 0)
        {
            var tournamentPool = new List<string>();
            var fitnessesPool = new List<double>();
            int tournamenSize = 10;
            for (int i = 0; i < tournamenSize; i++)
            {
                var rngIndex = random.Next(population.Count());
                tournamentPool.Add(population.ElementAt(rngIndex));
                fitnessesPool.Add(fitnesses.ElementAt(rngIndex));
            }
            return tournamentPool.Zip(fitnessesPool, (x, y) => new { dna = x, score = y }).OrderByDescending(x => x.score).FirstOrDefault().dna;
        }

        public string Mutate(string chromosome, double probability)
        {
            var chrom = chromosome.ToCharArray();
            for (int i = 0; i < chrom.Length; i++)
            {
                if (random.NextDouble() < probability)
                    chrom[i] = chrom[i] == '0' ? '1' : '0';
            }
            return new string(chrom);
        }

        public IEnumerable<string> Crossover(string chromosome1, string chromosome2)
        {
            var length = chromosome2.Length;
            var child1 = new char[length];
            var child2 = new char[length];
            for (int i = 0; i < length; i++)
            {
                if (random.NextDouble() > 0.5)
                {
                    child1[i] = chromosome1[i];
                    child2[i] = chromosome2[i];
                }
                else
                {
                    child1[i] = chromosome2[i];
                    child2[i] = chromosome1[i];
                }
            }
            return new string[] { new string(child1), new string(child2) };
        }


        public string Run(Func<string, double> fitness, int length, double p_c, double p_m, int iterations = 100)
        {
            var population = new List<string>();
            var fitnesses = new List<double>();
            int populationSize = 100;
            for (int i = 0; i < populationSize; i++)
            {
                var dna = Generate(length);
                population.Add(dna);
                fitnesses.Add(fitness(dna));
            }

            for (int k = 0; k < iterations; k++)
            {
                var newPopulation = new List<string>();
                for (int i = 0; i < populationSize / 2; i++)
                {
                    newPopulation.AddRange(Crossover(Select(population, fitnesses), Select(population, fitnesses)));
                }
                population = newPopulation;
                fitnesses.Clear();
                foreach (var dna in population)
                {
                    fitnesses.Add(fitness(dna));
                }
            }
            return population.Zip(fitnesses, (x, y) => new { dna = x, score = y }).OrderByDescending(x => x.score).FirstOrDefault().dna;
        }
    }

    [TestFixture]
    public class KataTest
    {
        private GeneticAlgorithm GA = new GeneticAlgorithm();
        private const int CL = 35;
        private Random random = new Random();

        [Test]
        public void _0_SmallTests()
        {
            StringBuilder sb;
            string goal;
            Func<string, double> f;
            int size = 4;

            for (int i = 0; i < 2; ++i)
            {
                sb = new StringBuilder(size);

                for (int j = 0; j < size; ++j)
                {
                    sb.Append(Math.Floor(2 * random.NextDouble()).ToString());
                }
                goal = sb.ToString();
                f = Fitness(goal);

                Assert.AreEqual(goal, GA.Run(f, size, 0.6, 0.002));
            }
        }

        [Test]
        public void _1_GeneticAlgorithm()
        {
            StringBuilder sb = new StringBuilder(CL);
            string goal;
            Func<string, double> f;

            for (int j = 0; j < CL; ++j)
            {
                sb.Append(Math.Floor(2 * random.NextDouble()).ToString());
            }
            goal = sb.ToString();
            f = Fitness(goal);

            Assert.AreEqual(goal, GA.Run(f, CL, 0.6, 0.002));
        }

        Func<string, double> Fitness(string goal)
        {
            return (c) =>
            {
                if (c.Length != goal.Length) return 0;
                int i = 0, count = new int[c.Length].Count(_ => goal[i] != c[i++]);
                return 1d / (count + 1);
            };
        }
    }
}