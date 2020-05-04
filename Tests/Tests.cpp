#include "pch.h"
#include "CppUnitTest.h"
#include "../Apotheke/Repository.h"
#include "../Apotheke/Repository.cpp"
#include "../Apotheke/MedicineDomain.h"
#include "../Apotheke/MedicineDomain.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Tests
{
	TEST_CLASS(MedicineClass)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			auto med = new Medicine("Euthyrox", 100, 345.99, 0);
			Assert::AreEqual(100.0, med->get_concentration());
			Assert::AreEqual(345.99, med->get_quantity());
			Assert::AreEqual(0.0, med->get_price());
			Assert::AreEqual(string("Euthyrox"), med->get_name());
		}

	};

	TEST_CLASS(RepositoryClass)
	{
	public:

		TEST_METHOD(AddTest)
		{
			auto repos = new Repository;

			bool useless = repos->add_med("Paracetamol", 50, 1000, 5);
			Medicine med = repos->get_element("Paracetamol", 50);
			Assert::AreEqual(string("Paracetamol"), med.get_name());
			Assert::AreEqual(50.0, med.get_concentration());
			Assert::AreEqual(1000.0, med.get_quantity());
			Assert::AreEqual(5.0, med.get_price());

			useless = repos->add_med("Paracetamol", 50, 1000, 5);
			Assert::AreEqual(2000.0, med.get_quantity());
		}

		TEST_METHOD(DeleteTest)
		{
			auto repos = new Repository;

			bool useless = repos->add_med("Vitamina C", 90, 5000, 2);

			repos->delete_med("Vitamina C", 90);
			auto med = repos->get_element("Vitamina C", 90);

			Assert::AreEqual(string(""), med.get_name());

		}

		TEST_METHOD(UpdateTest)
		{
			auto repos = new Repository;

			bool useless = repos->add_med("Vitamina C", 90, 5000, 2);

			repos->update_med("Vitamina C", 90, 10);
			auto med = repos->get_element("Vitamina C", 90);

			Assert::AreEqual(string("Vitamina C"), med.get_name());
			Assert::AreEqual(90.0, med.get_concentration());
			Assert::AreEqual(5000.0, med.get_quantity());
			Assert::AreEqual(10.0, med.get_price());

		}

		TEST_METHOD(SearchByName)
		{
			auto repos = new Repository;

			bool cases = repos->search_by_name("Oreo");

			Assert::IsFalse(cases);

			bool useless = repos->add_med("Vitamina C", 90, 5000, 2);

			cases = repos->search_by_name("C");

			Assert::IsTrue(cases);

		}

		TEST_METHOD(SearchByQuantity)
		{
			auto repos = new Repository;

			bool useless = repos->add_med((string)"Vitamina C", 90, 5000, 2);
			Assert::IsTrue(repos->search_by_quantity(1001));

			useless = repos->add_med("Paracetamol", 50, 1000, 5);

			Assert::IsTrue(repos->search_by_quantity(1001));
			Assert::IsFalse(repos->search_by_quantity(1000));

		}

		TEST_METHOD(GroupByPrice)
		{
			auto repos = new Repository;

			bool useless = repos->add_med((string)"Vitamina C", 90, 5000, 2);
			useless = repos->add_med("Paracetamol", 50, 1000, 5);
			useless = repos->add_med("Nurofen", 70, 10000, 10.5);

			Repository temp = repos->group_by_price();
			for (int i = 0; i < repos->meds.size(); i++)
			{
				Assert::IsTrue(repos->meds[i].get_price() == temp.meds[i].get_price());
			}
		}
	};
}