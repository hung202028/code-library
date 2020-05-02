// Rule for determining "this"

/*
1. Is the function called with "new" (new binding) ?
   If so, "this" is the newly constructed object.

        var bar = new foo()

2. Is the function called with "call" or "apply" (explicit binding)? If so, "this" is
   the explicitly specified object.

        var bar = foo.call(obj)

3. Is the function called with a context (implicit binding), otherwise known as
   an owning or containing object? If so, "this" is that context object.

        var bar = obj.foo()

4. Otherwise, default "this" (default binding). If in "strict" mode, pick
   "undefined", otherwise pick the "global object".

* */