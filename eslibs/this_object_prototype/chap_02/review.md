Determining the "this" binding for an executing function requires finding the
direct call-site of that function.

Once examined, four rules can be applied to the call-site, in the following
order of precedence:

1. Call with "new"? Use the newly constructed object.

2. Call with "call" or "apply" or "bind"? Use the specified object.

3. Call with a context object owning the call? Use that context object.

4. Default: "undefined" in strict mode, "global" object otherwise.



Be careful of accidental/unintentional invoking of default binding rule. In case
you want safety ignore a "this" binding, a "DMZ" object like:
dmz = Object.create(null) is a good placeholder value that projects the global
object from unintended side effects.


Instead of four standard binding rules, ES6 arrow-function uses lexical scoping
for "this" binding, which means they inherit the "this" binding(whatever it is)
from its enclosing function call. They are essentally a syntactic replacement
of self = this in pre ES6 coding.