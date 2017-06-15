      
#include "stdafx.h"
#include "../CodingKata/coding_kata.h"

BOOST_AUTO_TEST_CASE( LocNoComments )  
{
	BOOST_CHECK_EQUAL(7, GetLinesOfCode(
R"CODE(
public class Hello1
{
   public static void Main()
   {
      System.Console.WriteLine("Hello, World!");
   }
}
)CODE")
	);
}

BOOST_AUTO_TEST_CASE(LocWithComments)
{
	BOOST_CHECK_EQUAL(7, GetLinesOfCode(
		R"CODE(
// Test app
public class Hello1
{
   public static void Main()
   {
	  /*
		multiline comments
	   */
      System.Console.WriteLine("Hello, World!"); // comment at the end of line
   }
}
)CODE")
);
}

BOOST_AUTO_TEST_CASE(LocLineStartsWithComment)
{
	BOOST_CHECK_EQUAL(7, GetLinesOfCode(
		R"CODE(
// Test app
public class Hello1
{
   public static void Main()
   {
	  /*
		multiline comments
	   */
      /* comment before statement */ System.Console.WriteLine("Hello, World!");
   }
}
)CODE")
);
}
