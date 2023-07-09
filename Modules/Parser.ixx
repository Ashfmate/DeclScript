export module Parser;
export import <vector>;
export import <string>;

export using std::vector, std::string;

/*
* Rules for script
* 
* Each code piece will be treated as a function and so will have return values
* 
* [for user defined names] (for optional tokens) <argument> {for code} //For explanation\\
* 
* Key word {var} : var [var_name](: data type) val1 val2 ... valn //return values are values entered for the variable\\
* 
* key word {set} : set [var_name]([index]) val1 val2 ... valn //return values are values entered for the variable\\
* 
* key word {print} : print val1 val2 ... valn (endl) //return values are values entered in the printing\\
* 
* key word {if} : if <expression> {code} (elf) <expression> {code} (else) {code} //return value is the number of if code block that was executed where the first if is 1 then elf is 2 and so on, else is 0. If nothing then -1\\
* 
* key word {while} : while <expression> {code} //return value is the number of iterations done\\
* 
* key word {iterate) : iterate [var_name] {code} //return value is the number of iterations done\\
* 
* key word {for} : for start_val end_val {code} //return value is the absolute difference between start_val and end_val\\
* 
* key word {function} : function <param1> <param2> <param3> {code} //return values are determined by the helper key word return which if it exist will return the variable values it is returning else it will return nothing
* 
*/

export namespace parse
{
	class Parser
	{
	public:
		Parser();

	private:
		vector<string> m_declaratives;
		vector<string> m_helper_key_words;
	};
}

export namespace parse
{
	Parser::Parser()
	{
		m_declaratives = { "var", "set", "print", "if", "while", "iterate", "for", "function" };
		m_helper_key_words = 
		{ 
			"endl", // specific for printing
			"elf", "else", // Specific for if-else
			"integer", "double", "boolean", "string", "nil", // Specific for var setting
			"#", "break", "continue", // Specific for loops
			"return" // Specific for functions
		};
	}
}