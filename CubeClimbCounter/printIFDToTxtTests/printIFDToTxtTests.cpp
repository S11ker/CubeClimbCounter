#include "pch.h"
#include "CppUnitTest.h"
#include "../CubeClimbCounter/WorkWithIFDInTxtFile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace printIFDToTxtTests
{
	TEST_CLASS(printIFDToTxtTests)
	{
	public:

		TEST_METHOD(fileFormatDoesNotMatchToTxt)
		{
			string errorText = "NULL";
			string expErrorText = "Fail: Invalid file format";

			try
			{
				printIFDToTxt("output.png", NULL);
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(positiveIntNumber)
		{
			int N = 199;
			
			string line = "NULL";
			string expLine = "199";

			string errorText = "NULL";
			
			try
			{
				printIFDToTxt("output.txt", N);
				ifstream inputFile("output.txt");
				getline(inputFile, line);
				
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}

		TEST_METHOD(positiveBigIntNumber)
		{
			int N = 89674589;
			
			string line = "NULL";
			string expLine = "89674589";

			string errorText = "NULL";

			try
			{
				printIFDToTxt("output.txt", N);
				ifstream inputFile("output.txt");
				getline(inputFile, line);

			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}

		TEST_METHOD(positiveFloatNumber)
		{
			float N = 89.6;
			
			string line = "NULL";
			string expLine = "89.599998";

			string errorText = "NULL";

			try
			{
				printIFDToTxt("output.txt", N);
				ifstream inputFile("output.txt");
				getline(inputFile, line);

			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}

		TEST_METHOD(positiveDoubleNumber)
		{
			double N = 89.674589;
			
			string line = "NULL";
			string expLine = "89.674589";

			string errorText = "NULL";

			try
			{
				printIFDToTxt("output.txt", N);

				ifstream inputFile("output.txt");
				getline(inputFile, line);

			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}

		TEST_METHOD(negativeIntNumber)
		{
			int N = -896;

			string line = "NULL";
			string expLine = "-896";

			string errorText = "NULL";

			try
			{
				printIFDToTxt("output.txt", N);
				ifstream inputFile("output.txt");
				getline(inputFile, line);

			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}

		TEST_METHOD(negativeBigIntNumber)
		{
			int N = -89674589;

			string line = "NULL";
			string expLine = "-89674589";

			string errorText = "NULL";

			try
			{
				printIFDToTxt("output.txt", N);
				ifstream inputFile("output.txt");
				getline(inputFile, line);

			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}

		TEST_METHOD(negativeFloatNumber)
		{
			float N = -89.6;

			string line = "NULL";
			string expLine = "-89.599998";

			string errorText = "NULL";

			try
			{
				printIFDToTxt("output.txt", N);
				ifstream inputFile("output.txt");
				getline(inputFile, line);

			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}

		TEST_METHOD(negativeDoubleNumber)
		{
			double N = -89.674589;

			string line = "NULL";
			string expLine = "-89.674589";

			string errorText = "NULL";

			try
			{
				printIFDToTxt("output.txt", N);

				ifstream inputFile("output.txt");
				getline(inputFile, line);

			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}

		TEST_METHOD(positiveDoubleNumberWithZeros)
		{
			double N = 89.60000000;

			string line = "NULL";
			string expLine = "89.6";

			string errorText = "NULL";

			try
			{
				printIFDToTxt("output.txt", N);

				ifstream inputFile("output.txt");
				getline(inputFile, line);

			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}

		TEST_METHOD(negativeDoubleNumberWithZeros)
		{
			double N = -89.60000000;

			string line = "NULL";
			string expLine = "-89.6";

			string errorText = "NULL";

			try
			{
				printIFDToTxt("output.txt", N);

				ifstream inputFile("output.txt");
				getline(inputFile, line);

			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expLine, line);
		}


	};
}