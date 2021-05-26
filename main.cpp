#include <UnitTest++/UnitTest++.h>
#include <../GenRand/GenRand.cpp>

struct GenRand_fixture {
	GenRand * object;
	GenRand_fixture() {
		object = new GenRand();
		vector<int> reg_all = {1,1,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,1};
		object->setReg(reg_all);
	}
	~GenRand_fixture() {
		delete object;
	}
};

SUITE(KeyTest)
{
	vector<int> reg1 = {1,1,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,1};
	TEST_FIXTURE(GenRand_fixture, CorrectData){
		object->setReg(reg1);
		CHECK(true);
	}
	vector<int> reg2 = {1,1,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,1,1,0,0,1,1,0,1,1,1,0,0,1};
	TEST_FIXTURE(GenRand_fixture, ZeroLength){
		CHECK_THROW(object->setReg(reg2), GenRandError);
	}
	vector<int> reg3 = {1,1,0,1,0,0,1,0,1,1,0,1};
	TEST_FIXTURE(GenRand_fixture, InvalidCharacter){
		CHECK_THROW(object->setReg(reg3), GenRandError);
	}
	vector<int> reg4 = {};
	TEST_FIXTURE(GenRand_fixture, ZeroCase){
		CHECK_THROW(object->setReg(reg4), GenRandError);
	}
	vector<int> reg5 = {1,1,0,1,6,9,1,0,1,1,0,1,1,1,1,0,0,5,1,0,5,5,1,1};
	TEST_FIXTURE(GenRand_fixture, InvalidCharactfer){
		CHECK_THROW(object->setReg(reg5), GenRandError);
	}
	vector<int> reg6 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	TEST_FIXTURE(GenRand_fixture, CaseIsShort){
		CHECK_THROW(object->setReg(reg6), GenRandError);
	}
	
}


SUITE(GenerateTest) {
	TEST_FIXTURE(GenRand_fixture, CorrectData){
		object->gen(5);
		CHECK(true);
	}
	TEST_FIXTURE(GenRand_fixture, ZeroLength){
		CHECK_THROW(object->gen(0), GenRandError);
	}
	TEST_FIXTURE(GenRand_fixture, ThereIsLetter){
		CHECK_THROW(object->gen(-5), GenRandError);
	}
}

int main(int argc, char **argv) {
	return UnitTest::RunAllTests();
}