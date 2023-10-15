#include "pch.h"
#include "CppUnitTest.h"
#include "../CubeClimbCounter/WorkWithIFDInTxtFile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace extractIFDFromTxtTests
{
	TEST_CLASS(extractIFDFromTxtTests)
	{
	public:

		TEST_METHOD(fileFormatDoesNotMatchToTxt)
		{
			int N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: Invalid file format";

			try {
				auto res = extractIFDFromTxt("input.png");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(fileDoesNotExistOrNotOpen)
		{
			int N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: Could not open the file";

			try {
				auto res = extractIFDFromTxt("notOpen.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(fileIsAbsolutelyEmpty)
		{
			int N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: File is empty";

			try {
				auto res = extractIFDFromTxt("inputEmpty1.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(numberInFileNotOnFirstLine)
		{
			int N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("inputEmpty2.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(numberInFileAfterNull)
		{
			int N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("inputEmpty3.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(positiveIntNumber)
		{
			int N = NULL;
			int expN = 199;

			string errorText = nullptr;

			try {
				auto res = extractIFDFromTxt("input1.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expN, N);
		}

		TEST_METHOD(positiveBigIntNumber)
		{
			int N = NULL;
			int expN = 89674589;

			string errorText = nullptr;

			try {
				auto res = extractIFDFromTxt("input2.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expN, N);
		}

		TEST_METHOD(positiveFloatNumber)
		{
			float N = NULL;
			float expN = 89.6;

			string errorText = nullptr;

			try {
				auto res = extractIFDFromTxt("input3.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expN, N);
		}

		TEST_METHOD(positiveDoubleNumber)
		{
			double N = NULL;
			double expN = 89.674589;

			string errorText = nullptr;

			try {
				auto res = extractIFDFromTxt("input4.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expN, N);
		}

		TEST_METHOD(negativeIntNumber)
		{
			int N = NULL;
			int expN = -896;

			string errorText = nullptr;

			try {
				auto res = extractIFDFromTxt("input5.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expN, N);
		}

		TEST_METHOD(negativeBigIntNumber)
		{
			int N = NULL;
			int expN = -89674589;

			string errorText = nullptr;

			try {
				auto res = extractIFDFromTxt("input6.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expN, N);
		}

		TEST_METHOD(negativeFloatNumber)
		{
			float N = NULL;
			float expN = -89.6;

			string errorText = nullptr;

			try {
				auto res = extractIFDFromTxt("input7.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expN, N);
		}

		TEST_METHOD(negativeDoubleNumber)
		{
			double N = NULL;
			double expN = -89.674589;

			string errorText = nullptr;

			try {
				auto res = extractIFDFromTxt("input8.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expN, N);
		}

		TEST_METHOD(positiveIntNumberButAfterLetters)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input9.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(positiveFloatNumberButAfterLetters)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input10.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(positiveDoubleNumberButAfterLetters)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input11.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(negativeIntNumberButAfterLetters)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input12.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(negativeFloatNumberButAfterLetters)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input13.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(negativeDoubleNumberButAfterLetters)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input14.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(positiveIntNumberButAfterEscape)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input15.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(positiveFloatNumberButAfterEscape)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input16.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(positiveDoubleNumberButAfterEscape)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input17.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(negativeIntNumberButAfterEscape)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input18.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(negativeFloatNumberButAfterEscape)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input19.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(negativeDoubleNumberButAfterEscape)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input20.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(positiveIntNumberButAfterEscapeAndSpec)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input21.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(onlyLettersInFile)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input22.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(onlyEntersAndTabsInFile)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input23.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(onlySpecInFile)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input24.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

		TEST_METHOD(onlyEscapeInFile)
		{
			double N = NULL;

			string errorText = nullptr;
			string expErrorText = "Fail: It is impossible to determine the type of number in a string";

			try {
				auto res = extractIFDFromTxt("input25.txt");

				if (holds_alternative<int>(res)) {
					N = get<int>(res);
				}
				else if (holds_alternative<float>(res)) {
					N = get<float>(res);
				}
				else if (holds_alternative<double>(res)) {
					N = get<double>(res);
				}
			}
			catch (const exception& error)
			{
				errorText = error.what();
			}
			Assert::AreEqual(expErrorText, errorText);
		}

	};
}
