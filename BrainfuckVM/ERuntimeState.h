#ifndef BRAINFUCK_VM_E_RUNTIME_STATE_H
#	define BRAINFUCK_VM_E_RUNTIME_STATE_H

/// <summary>
/// Brainfuck VM namespace
/// </summary>
namespace BrainfuckVM
{
	/// <summary>
	/// Runtime state enumerator
	/// </summary>
	enum ERuntimeState
	{
		/// <summary>
		/// No operation runtime state
		/// </summary>
		ERuntimeState_NoOperation,

		/// <summary>
		/// Finished runtime state
		/// </summary>
		ERuntimeState_Finished,

		/// <summary>
		/// OK runtime state
		/// </summary>
		ERuntimeState_OK,

		/// <summary>
		/// Pointer underflow runtime state
		/// </summary>
		ERuntimeState_PointerUnderflow,

		/// <summary>
		/// Stack underflow runtime state
		/// </summary>
		ERuntimeState_StackUnderflow,

		/// <summary>
		/// Stack overflow runtime state
		/// </summary>
		ERuntimeState_StackOverflow,

		/// <summary>
		/// Out of memory runtime state
		/// </summary>
		ERuntimeState_OutOfMemory
	};
}

#endif
