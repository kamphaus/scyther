#ifndef SWITCHES
#define SWITCHES

#include "term.h"
#include "system.h"

void switchesInit ();
void switchesDone ();

//! Command-line switches structure
struct switchdata
{
  // Command-line
  int argc;
  char **argv;

  // Methods
  int engine;			//!< Engine type (POR_ENGINE,ARACHNE_ENGINE)
  int match;			//!< Matching type.
  int clp;			//!< Do we use clp?
  int tupling;			//!< Tupling is by default 0: right-associative, optionally 1: left-associative.

  // Pruning and Bounding
  int prune;			//!< Type of pruning.
  int maxproofdepth;		//!< Maximum proof depth
  int maxtracelength;		//!< Maximum trace length allowed
  int runs;			//!< The number of runs as in the switch
  Term filterClaim;		//!< Which claim should be checked?
  int maxAttacks;		//!< When not 0, maximum number of attacks

  // Modelchecker
  int traverse;			//!< Traversal method
  int forceChoose;		//!< Force chooses for each run, even if involved in first read
  int chooseFirst;		//!< Priority to chooses, implicit and explicit
  int readSymmetries;		//!< Enable read symmetry reduction
  int agentSymmetries;		//!< Enable agent symmetry reduction
  int orderSymmetries;		//!< Enable symmetry order reduction
  int pruneNomoreClaims;	//!< Enable no more claims cutter
  int reduceEndgame;		//!< Enable endgame cutter
  int reduceClaims;		//!< Symmetry reduction on claims (only works when switchAgentSymm is true)
  // Parallellism
  int scenario;			//!< -1 to count, 0 for disable, 1-n to select the choose scenario
  int scenarioSize;		//!< Scenario size, also called fixed trace prefix length

  // Arachne
  int arachneSelector;		//!< Goal selection method for Arachne engine
  int maxIntruderActions;	//!< Maximum number of intruder actions in the semitrace (encrypt/decrypt)
  int agentTypecheck;		//!< Check type of agent variables in all matching modes
  int concrete;			//!< Swap out variables at the end.
  int extravert;		//!< Disallow Alice talking to Alice
  int intruder;			//!< Enable intruder actions (default)

  // Misc
  int switchP;			//!< A multi-purpose integer parameter, passed to the partial order reduction method selected.
  int experimental;		//!< Experimental stuff goes here until it moves into main stuff.
  int removeclaims;		//!< Remove any claims in the spdl file
  int addreachableclaim;	//!< Adds 'reachable' claims to each role
  int addallclaims;		//!< Adds all sorts of claims to the roles
  int check;			//!< Check protocol correctness

  // Output
  int output;			//!< From enum outputs: what should be produced. Default ATTACK.
  int report;
  int reportClaims;		//!< Enable claims report
  int xml;			//!< xml output
  int human;			//!< human readable
  int reportMemory;		//!< Memory display switch.
  int reportTime;		//!< Time display switch.
  int reportStates;		//!< Progress display switch. (traversed states)
  int countStates;		//!< Count states
  int extendNonReads;		//!< Show further events in arachne xml output.
  int extendTrivial;		//!< Show further events in arachne xml output, based on knowledge underapproximation. (Includes at least the events of the nonreads extension)
  int plain;			//!< Disable color output

  //! Latex output switch.
  /**
   * Obsolete. Use globalLatex instead.
   *\sa globalLatex
   */
  int latex;
};

extern struct switchdata switches;	//!< pointer to switchdata structure

#endif
