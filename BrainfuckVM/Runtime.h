#ifndef BRAINFUCK_VM_RUNTIME_H
#	define BRAINFUCK_VM_RUNTIME_H

#	include <cstdint>
#	include <vector>
#	include <stack>
#	include <string>
#	include "ERuntimeState.h"

/// <summary>
/// Brainfuck VM namespace
/// </summary>
namespace BrainfuckVM
{
	/// <summary>
	/// Brainfuck runtime class
	/// </summary>
	class Runtime
	{
	private:
		/// <summary>
		/// Source
		/// </summary>
		std::string source;

		/// <summary>
		/// Memory
		/// </summary>
		std::vector<int8_t> memory;

		/// <summary>
		/// Program counter stack
		/// </summary>
		std::stack<size_t> programCounterStack;

		/// <summary>
		/// Pointer
		/// </summary>
		size_t pointer;

	public:
		/// <summary>
		/// Default constructor
		/// </summary>
		Runtime();

		/// <summary>
		/// Destructor
		/// </summary>
		~Runtime();

		/// <summary>
		/// Load program
		/// </summary>
		/// <param name="source">Source</param>
		void Load(const std::string & source);

		/// <summary>
		/// Interpret program
		/// </summary>
		/// <param name="source">Source</param>
		/// <param name="optRuntimeState">Runtime state (optional)</param>
		/// <returns>Exit code</returns>
		int8_t Interpret(const std::string & source, ERuntimeState *optRuntimeState = nullptr);

		/// <summary>
		/// Execute loaded program
		/// </summary>
		/// <param name="optRuntimeState">Runtime state (optional)</param>
		/// <returns>Exit code</returns>
		int8_t Execute(ERuntimeState *optRuntimeState = nullptr);

		/// <summary>
		/// Do execution step
		/// </summary>
		/// <returns>Runtime state</returns>
		ERuntimeState Step();

		/// <summary>
		/// Reset runtime
		/// </summary>
		void Reset();

		/// <summary>
		/// Get program counter
		/// </summary>
		/// <returns>Program counter</returns>
		size_t GetProgramCounter();

		/// <summary>
		/// Read value from memory
		/// </summary>
		/// <returns>Value from memory</returns>
		int8_t ReadValue();

		/// <summary>
		/// Read value from memory
		/// </summary>
		/// <param name="position">Position</param>
		/// <returns>Read value from memory</returns>
		int8_t ReadValue(size_t position);
	};
}

#endif
