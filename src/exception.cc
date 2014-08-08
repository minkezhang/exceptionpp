#include <sstream>

#include "libs/stacktrace/call_stack.hpp"

#include "src/exception.h"

const char *exceptionpp::BaseError::what() const throw() { return(this->buffer.c_str()); }

exceptionpp::InvalidOperation::InvalidOperation(std::string func_name, std::string msg) {
	this->func_name = func_name;
	this->msg = msg;

	stacktrace::call_stack st;

	std::stringstream buffer;
	buffer << "InvalidOperation(" << this->func_name << "): Invalid operation on " << this->func_name << "() -- " << this->msg << std::endl << st.to_string();
	this->buffer = buffer.str();
}

exceptionpp::RuntimeError::RuntimeError(std::string func_name, std::string msg) {
	this->func_name = func_name;
	this->msg = msg;

	stacktrace::call_stack st;

	std::stringstream buffer;
	buffer << "RuntimeError(" << this->func_name << "): " << this->func_name << "() -- " << this->msg << std::endl << st.to_string();
	this->buffer = buffer.str();
}

exceptionpp::NotImplemented::NotImplemented(std::string func_name) {
	this->func_name = func_name;

	std::stringstream buffer;
	buffer << "NotImplemented(" << this->func_name << "): Method not implemented " << this->func_name << "()";
	this->buffer = buffer.str();
}
