#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <exception>
#include <string>

/**
 * the exceptions listed here MAY be called by the user in try / catch blocks
 */
namespace exceptionpp {
	class BaseError : public std::exception {
		public:
			virtual const char *what() const throw();
		protected:
			std::string buffer;
	};

	class NotImplemented : public BaseError {
		public:
			NotImplemented(std::string func_name);
		protected:
			std::string func_name;
	};

	/* user error -- malicious data, invalid arguments, etc. */
	class InvalidOperation : public BaseError {
		public:
			InvalidOperation(std::string func_name, std::string msg);
		protected:
			std::string func_name;
			std::string msg;
	};

	/* program error -- stack overflow, null pointer, etc. */
	class RuntimeError : public BaseError {
		public:
			RuntimeError(std::string func_name, std::string msg);
		protected:
			std::string func_name;
			std::string msg;
	};
}

#endif
