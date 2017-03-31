/*
 * unittest_runner.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: daeden
 */
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/XmlOutputter.h>
#include "MyXmlOutputterHook.h"


int main(int argc, char* argv[])
{
  // Get the top level suite from the registry
  CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( suite );

  std::ofstream outputFile("testResults.xml");

  CppUnit::XmlOutputter* outputter = new CppUnit::XmlOutputter( &runner.result(),
                                                                outputFile );
  MyXmlOutputterHook hook("MatrixMult", "Gilberto L. Perez");
  outputter->addHook(&hook);
  runner.setOutputter(outputter);
  // Change the default outputter to a compiler error format outputter
  //runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
  //                                                    std::cerr ) );
  // Run the tests.
  bool wasSucessful = runner.run();

  // Return error code 1 if the one of test failed.
  outputFile.close();

  return 0;
}
