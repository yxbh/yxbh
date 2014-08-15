#pragma once

/// remove unused parameter warning.
#define UNUSED_PARAMETER(X) (void)X;
#define BH_UNUSED(X) UNUSED_PARAMETER(X)
#define BH_UNUSED_PARAMETER(X) UNUSED_PARAMETER(X)

/*
 * The following set of macros allow the creation of unique variable names within the current scope.
 * Taken from: http://stackoverflow.com/questions/2419650/c-c-macro-template-blackmagic-to-generate-unique-name
*/
/// boiler-plate
#define CONCATENATE_DETAIL(x, y) x##y
/// boiler-plate
#define CONCATENATE(x, y) CONCATENATE_DETAIL(x, y)
/// @return an unique name base on the given 'variable' name by concatenating __COUNTER__.
#define MAKE_UNIQUE_NAME_WITH(x) CONCATENATE(x, __COUNTER__)
/// @return an unique name which is constructed by concatenating 'UNIQUE_VAR_NAME' and __COUNTER__ together.
#define MAKE_UNIQUE_NAME() CONCATENATE(UNIQUE_VAR_NAME_, __COUNTER__)
/// @return an unique name base on the given 'variable' name by concatenating __COUNTER__.
#define BH_MAKE_UNIQUE_NAME_WITH(x) CONCATENATE(x, __COUNTER__)
/// @return an unique name which is constructed by concatenating 'UNIQUE_VAR_NAME' and __COUNTER__ together.
#define BH_MAKE_UNIQUE_NAME() CONCATENATE(UNIQUE_VAR_NAME_, __COUNTER__)
