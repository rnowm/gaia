
/**
 * alameda 0.0.6 Copyright (c) 2011-2012, The Dojo Foundation All Rights Reserved.
 * Available via the MIT or new BSD license.
 * see: http://github.com/requirejs/alameda for details
 */
//Going sloppy to avoid 'use strict' string cost, but strict practices should
//be followed.
/*jslint sloppy: true, nomen: true, regexp: true */
/*global setTimeout, process, document, navigator, importScripts */

var requirejs, require, define;
(function (global, undef) {
    var prim, topReq, dataMain,
        bootstrapConfig = requirejs || require,
        hasOwn = Object.prototype.hasOwnProperty,
        contexts = {},
        queue = [],
        currDirRegExp = /^\.\//,
        urlRegExp = /^\/|\:|\?|\.js$/,
        commentRegExp = /(\/\*([\s\S]*?)\*\/|([^:]|^)\/\/(.*)$)/mg,
        cjsRequireRegExp = /[^.]\s*require\s*\(\s*["']([^'"\s]+)["']\s*\)/g,
        jsSuffixRegExp = /\.js$/;

    if (typeof requirejs === 'function') {
        return;
    }

    function hasProp(obj, prop) {
        return hasOwn.call(obj, prop);
    }

    function getOwn(obj, prop) {
        return obj && hasProp(obj, prop) && obj[prop];
    }

    /**
     * Cycles over properties in an object and calls a function for each
     * property value. If the function returns a truthy value, then the
     * iteration is stopped.
     */
    function eachProp(obj, func) {
        var prop;
        for (prop in obj) {
            if (hasProp(obj, prop)) {
                if (func(obj[prop], prop)) {
                    break;
                }
            }
        }
    }

    /**
     * Mixes in properties from source into target,
     * but only if target does not already have a property of the same name.
     */
    function mixin(target, source, force, deepStringMixin) {
        if (source) {
            eachProp(source, function (value, prop) {
                if (force || !hasProp(target, prop)) {
                    if (deepStringMixin && typeof value !== 'string') {
                        if (!target[prop]) {
                            target[prop] = {};
                        }
                        mixin(target[prop], value, force, deepStringMixin);
                    } else {
                        target[prop] = value;
                    }
                }
            });
        }
        return target;
    }

    //Allow getting a global that expressed in
    //dot notation, like 'a.b.c'.
    function getGlobal(value) {
        if (!value) {
            return value;
        }
        var g = global;
        value.split('.').forEach(function (part) {
            g = g[part];
        });
        return g;
    }

    //START prim
    /**
     * Changes from baseline prim
     * - no hasProp or hasOwn (already defined in this file)
     * - no hideResolutionConflict, want early errors, trusted code.
     * - each() changed to Array.forEach
     * - removed UMD registration
     */
    /**
     * prim 0.0.3 Copyright (c) 2012-2013, The Dojo Foundation All Rights Reserved.
     * Available via the MIT or new BSD license.
     * see: http://github.com/requirejs/prim for details
     */

    /*global setImmediate, process, setTimeout */
    (function () {
        
        var waitingId,
            waiting = [];

        function check(p) {
            if (hasProp(p, 'e') || hasProp(p, 'v')) {
                throw new Error('nope');
            }
            return true;
        }

        function callWaiting() {
            waitingId = 0;
            var w = waiting;
            waiting = [];
            while (w.length) {
                w.shift()();
            }
        }

        function asyncTick(fn) {
            waiting.push(fn);
            if (!waitingId) {
                waitingId = setTimeout(callWaiting, 0);
            }
        }

        function syncTick(fn) {
            fn();
        }

        function notify(ary, value) {
            prim.nextTick(function () {
                ary.forEach(function (item) {
                    item(value);
                });
            });
        }

        prim = function prim(options) {
            var p,
                ok = [],
                fail = [],
                nextTick = options && options.sync ? syncTick : prim.nextTick;

            return (p = {
                callback: function (yes, no) {
                    if (no) {
                        p.errback(no);
                    }

                    if (hasProp(p, 'v')) {
                        nextTick(function () {
                            yes(p.v);
                        });
                    } else {
                        ok.push(yes);
                    }
                },

                errback: function (no) {
                    if (hasProp(p, 'e')) {
                        nextTick(function () {
                            no(p.e);
                        });
                    } else {
                        fail.push(no);
                    }
                },

                finished: function () {
                    return hasProp(p, 'e') || hasProp(p, 'v');
                },

                rejected: function () {
                    return hasProp(p, 'e');
                },

                resolve: function (v) {
                    if (check(p)) {
                        p.v = v;
                        notify(ok, v);
                    }
                    return p;
                },
                reject: function (e) {
                    if (check(p)) {
                        p.e = e;
                        notify(fail, e);
                    }
                    return p;
                },

                start: function (fn) {
                    p.resolve();
                    return p.promise.then(fn);
                },

                promise: {
                    then: function (yes, no) {
                        var next = prim(options);

                        p.callback(function (v) {
                            try {
                                if (yes && typeof yes === 'function') {
                                    v = yes(v);
                                }

                                if (v && typeof v.then === 'function') {
                                    v.then(next.resolve, next.reject);
                                } else {
                                    next.resolve(v);
                                }
                            } catch (e) {
                                next.reject(e);
                            }
                        }, function (e) {
                            var err;

                            try {
                                if (!no || typeof no !== 'function') {
                                    next.reject(e);
                                } else {
                                    err = no(e);

                                    if (err && typeof err.then === 'function') {
                                        err.then(next.resolve, next.reject);
                                    } else {
                                        next.resolve(err);
                                    }
                                }
                            } catch (e2) {
                                next.reject(e2);
                            }
                        });

                        return next.promise;
                    },

                    fail: function (no) {
                        return p.promise.then(null, no);
                    },

                    end: function () {
                        p.errback(function (e) {
                            throw e;
                        });
                    }
                }
            });
        };
        prim.serial = function (ary) {
            var result = prim().resolve().promise;
            ary.forEach(function (item) {
                result = result.then(function () {
                    return item();
                });
            });
            return result;
        };

        prim.nextTick = typeof setImmediate === 'function' ? setImmediate :
            (typeof process !== 'undefined' && process.nextTick ?
                process.nextTick : (typeof setTimeout !== 'undefined' ?
                    asyncTick : syncTick));
    }());
    //END prim

    function newContext(contextName) {
        var req, main, makeMap, callDep, handlers, checkingLater, load, context,
            defined = {},
            waiting = {},
            config = {
                //Defaults. Do not set a default for map
                //config to speed up normalize(), which
                //will run faster if there is no default.
                waitSeconds: 7,
                baseUrl: './',
                paths: {},
                pkgs: {},
                shim: {},
                config: {}
            },
            mapCache = {},
            requireDeferreds = [],
            deferreds = {},
            calledDefine = {},
            calledPlugin = {},
            loadCount = 0,
            startTime = (new Date()).getTime(),
            errCount = 0,
            trackedErrors = {},
            urlFetched = {};

        /**
         * Trims the . and .. from an array of path segments.
         * It will keep a leading path segment if a .. will become
         * the first path segment, to help with module name lookups,
         * which act like paths, but can be remapped. But the end result,
         * all paths that use this function should look normalized.
         * NOTE: this method MODIFIES the input array.
         * @param {Array} ary the array of path segments.
         */
        function trimDots(ary) {
            var i, part;
            for (i = 0; ary[i]; i += 1) {
                part = ary[i];
                if (part === '.') {
                    ary.splice(i, 1);
                    i -= 1;
                } else if (part === '..') {
                    if (i === 1 && (ary[2] === '..' || ary[0] === '..')) {
                        //End of the line. Keep at least one non-dot
                        //path segment at the front so it can be mapped
                        //correctly to disk. Otherwise, there is likely
                        //no path mapping for a path starting with '..'.
                        //This can still fail, but catches the most reasonable
                        //uses of ..
                        break;
                    } else if (i > 0) {
                        ary.splice(i - 1, 2);
                        i -= 2;
                    }
                }
            }
        }

        /**
         * Given a relative module name, like ./something, normalize it to
         * a real name that can be mapped to a path.
         * @param {String} name the relative name
         * @param {String} baseName a real name that the name arg is relative
         * to.
         * @param {Boolean} applyMap apply the map config to the value. Should
         * only be done if this normalization is for a dependency ID.
         * @returns {String} normalized name
         */
        function normalize(name, baseName, applyMap) {
            var pkgName, pkgConfig, mapValue, nameParts, i, j, nameSegment,
                foundMap, foundI, foundStarMap, starI,
                baseParts = baseName && baseName.split('/'),
                normalizedBaseParts = baseParts,
                map = applyMap && config.map,
                starMap = map && map['*'];

            //Adjust any relative paths.
            if (name && name.charAt(0) === '.') {
                //If have a base name, try to normalize against it,
                //otherwise, assume it is a top-level require that will
                //be relative to baseUrl in the end.
                if (baseName) {
                    if (getOwn(config.pkgs, baseName)) {
                        //If the baseName is a package name, then just treat it as one
                        //name to concat the name with.
                        normalizedBaseParts = baseParts = [baseName];
                    } else {
                        //Convert baseName to array, and lop off the last part,
                        //so that . matches that 'directory' and not name of the baseName's
                        //module. For instance, baseName of 'one/two/three', maps to
                        //'one/two/three.js', but we want the directory, 'one/two' for
                        //this normalization.
                        normalizedBaseParts = baseParts.slice(0, baseParts.length - 1);
                    }

                    name = normalizedBaseParts.concat(name.split('/'));
                    trimDots(name);

                    //Some use of packages may use a . path to reference the
                    //'main' module name, so normalize for that.
                    pkgConfig = getOwn(config.pkgs, (pkgName = name[0]));
                    name = name.join('/');
                    if (pkgConfig && name === pkgName + '/' + pkgConfig.main) {
                        name = pkgName;
                    }
                } else if (name.indexOf('./') === 0) {
                    // No baseName, so this is ID is resolved relative
                    // to baseUrl, pull off the leading dot.
                    name = name.substring(2);
                }
            }

            //Apply map config if available.
            if (applyMap && (baseParts || starMap) && map) {
                nameParts = name.split('/');

                for (i = nameParts.length; i > 0; i -= 1) {
                    nameSegment = nameParts.slice(0, i).join('/');

                    if (baseParts) {
                        //Find the longest baseName segment match in the config.
                        //So, do joins on the biggest to smallest lengths of baseParts.
                        for (j = baseParts.length; j > 0; j -= 1) {
                            mapValue = getOwn(map, baseParts.slice(0, j).join('/'));

                            //baseName segment has config, find if it has one for
                            //this name.
                            if (mapValue) {
                                mapValue = getOwn(mapValue, nameSegment);
                                if (mapValue) {
                                    //Match, update name to the new value.
                                    foundMap = mapValue;
                                    foundI = i;
                                    break;
                                }
                            }
                        }
                    }

                    if (foundMap) {
                        break;
                    }

                    //Check for a star map match, but just hold on to it,
                    //if there is a shorter segment match later in a matching
                    //config, then favor over this star map.
                    if (!foundStarMap && starMap && getOwn(starMap, nameSegment)) {
                        foundStarMap = getOwn(starMap, nameSegment);
                        starI = i;
                    }
                }

                if (!foundMap && foundStarMap) {
                    foundMap = foundStarMap;
                    foundI = starI;
                }

                if (foundMap) {
                    nameParts.splice(0, foundI, foundMap);
                    name = nameParts.join('/');
                }
            }

            return name;
        }


        function makeShimExports(value) {
            function fn() {
                var ret;
                if (value.init) {
                    ret = value.init.apply(global, arguments);
                }
                return ret || (value.exports && getGlobal(value.exports));
            }
            return fn;
        }

        function takeQueue(anonId) {
            var i, id, args, shim;
            for (i = 0; i < queue.length; i += 1) {
                //Peek to see if anon
                if (typeof queue[i][0] !== 'string') {
                    if (anonId) {
                        queue[i].unshift(anonId);
                        anonId = undef;
                    } else {
                        //Not our anon module, stop.
                        break;
                    }
                }
                args = queue.shift();
                id = args[0];
                i -= 1;

                if (!hasProp(defined, id) && !hasProp(waiting, id)) {
                    if (hasProp(deferreds, id)) {
                        main.apply(undef, args);
                    } else {
                        waiting[id] = args;
                    }
                }
            }

            //if get to the end and still have anonId, then could be
            //a shimmed dependency.
            if (anonId) {
                shim = getOwn(config.shim, anonId) || {};
                main(anonId, shim.deps || [], shim.exportsFn);
            }
        }

        function makeRequire(relName, topLevel) {
            var req = function (deps, callback, errback, alt) {
                var name, cfg;

                if (topLevel) {
                    takeQueue();
                }

                if (typeof deps === "string") {
                    if (handlers[deps]) {
                        return handlers[deps](relName);
                    }
                    //Just return the module wanted. In this scenario, the
                    //deps arg is the module name, and second arg (if passed)
                    //is just the relName.
                    //Normalize module name, if it contains . or ..
                    name = makeMap(deps, relName, true).id;
                    if (!hasProp(defined, name)) {
                        throw new Error('Not loaded: ' + name);
                    }
                    return defined[name];
                } else if (deps && !Array.isArray(deps)) {
                    //deps is a config object, not an array.
                    cfg = deps;
                    deps = undef;

                    if (Array.isArray(callback)) {
                        //callback is an array, which means it is a dependency list.
                        //Adjust args if there are dependencies
                        deps = callback;
                        callback = errback;
                        errback = alt;
                    }

                    if (topLevel) {
                        //Could be a new context, so call returned require
                        return req.config(cfg)(deps, callback, errback);
                    }
                }

                //Support require(['a'])
                callback = callback || function () {};

                //Simulate async callback;
                prim.nextTick(function () {
                    //Grab any modules that were defined after a
                    //require call.
                    takeQueue();
                    main(undef, deps || [], callback, errback, relName);
                });

                return req;
            };

            req.isBrowser = typeof document !== 'undefined' &&
                typeof navigator !== 'undefined';

            req.nameToUrl = function (moduleName, ext) {
                var paths, pkgs, pkg, pkgPath, syms, i, parentModule, url,
                    parentPath;

                //If a colon is in the URL, it indicates a protocol is used and it is just
                //an URL to a file, or if it starts with a slash, contains a query arg (i.e. ?)
                //or ends with .js, then assume the user meant to use an url and not a module id.
                //The slash is important for protocol-less URLs as well as full paths.
                if (urlRegExp.test(moduleName)) {
                    //Just a plain path, not module name lookup, so just return it.
                    //Add extension if it is included. This is a bit wonky, only non-.js things pass
                    //an extension, this method probably needs to be reworked.
                    url = moduleName + (ext || '');
                } else {
                    //A module that needs to be converted to a path.
                    paths = config.paths;
                    pkgs = config.pkgs;

                    syms = moduleName.split('/');
                    //For each module name segment, see if there is a path
                    //registered for it. Start with most specific name
                    //and work up from it.
                    for (i = syms.length; i > 0; i -= 1) {
                        parentModule = syms.slice(0, i).join('/');
                        pkg = getOwn(pkgs, parentModule);
                        parentPath = getOwn(paths, parentModule);
                        if (parentPath) {
                            //If an array, it means there are a few choices,
                            //Choose the one that is desired
                            if (Array.isArray(parentPath)) {
                                parentPath = parentPath[0];
                            }
                            syms.splice(0, i, parentPath);
                            break;
                        } else if (pkg) {
                            //If module name is just the package name, then looking
                            //for the main module.
                            if (moduleName === pkg.name) {
                                pkgPath = pkg.location + '/' + pkg.main;
                            } else {
                                pkgPath = pkg.location;
                            }
                            syms.splice(0, i, pkgPath);
                            break;
                        }
                    }

                    //Join the path parts together, then figure out if baseUrl is needed.
                    url = syms.join('/');
                    url += (ext || (/\?/.test(url) ? '' : '.js'));
                    url = (url.charAt(0) === '/' || url.match(/^[\w\+\.\-]+:/) ? '' : config.baseUrl) + url;
                }

                return config.urlArgs ? url +
                                        ((url.indexOf('?') === -1 ? '?' : '&') +
                                         config.urlArgs) : url;
            };

            /**
             * Converts a module name + .extension into an URL path.
             * *Requires* the use of a module name. It does not support using
             * plain URLs like nameToUrl.
             */
            req.toUrl = function (moduleNamePlusExt) {
                var index = moduleNamePlusExt.lastIndexOf('.'),
                    ext = null;

                if (index !== -1) {
                    ext = moduleNamePlusExt.substring(index, moduleNamePlusExt.length);
                    moduleNamePlusExt = moduleNamePlusExt.substring(0, index);
                }

                return req.nameToUrl(normalize(moduleNamePlusExt, relName), ext);
            };

            req.defined = function (id) {
                return hasProp(defined, makeMap(id, relName, true).id);
            };

            req.specified = function (id) {
                id = makeMap(id, relName, true).id;
                return hasProp(defined, id) || hasProp(deferreds, id);
            };

            return req;
        }

        function resolve(name, d, value) {
            if (name) {
                defined[name] = value;
            }
            d.resolve(value);
        }

        function makeNormalize(relName) {
            return function (name) {
                return normalize(name, relName, true);
            };
        }

        function defineModule(d) {
            var name = d.map.id,
                ret = d.factory.apply(defined[name], d.values);

            if (name) {
                //If setting exports via "module" is in play,
                //favor that over return value and exports.
                //After that, favor a non-undefined return
                //value over exports use.
                if (d.cjsModule && d.cjsModule.exports !== undef &&
                        d.cjsModule.exports !== defined[name]) {
                    ret = d.cjsModule.exports;
                } else if (ret === undef && d.usingExports) {
                    ret = defined[name];
                }
            } else {
                //Remove the require deferred from the list to
                //make cycle searching faster. Do not need to track
                //it anymore either.
                requireDeferreds.splice(requireDeferreds.indexOf(d), 1);
            }
            resolve(name, d, ret);
        }

        //This method is attached to every module deferred,
        //so the "this" in here is the module deferred object.
        function depFinished(val, i) {
            if (!this.rejected() && !this.depDefined[i]) {
                this.depDefined[i] = true;
                this.depCount += 1;
                this.values[i] = val;
                if (!this.depending && this.depCount === this.depMax) {
                    defineModule(this);
                }
            }
        }

        function makeDefer(name) {
            var d = prim({
                sync: !!name
            });
            d.map = name ? makeMap(name, null, true) : {};
            d.depCount = 0;
            d.depMax = 0;
            d.values = [];
            d.depDefined = [];
            d.depFinished = depFinished;
            if (d.map.pr) {
                //Plugin resource ID, implicitly
                //depends on plugin. Track it in deps
                //so cycle breaking can work
                d.deps = [makeMap(d.map.pr)];
            }
            return d;
        }

        function getDefer(name) {
            var d;
            if (name) {
                d = hasProp(deferreds, name) && deferreds[name];
                if (!d) {
                    d = deferreds[name] = makeDefer(name);
                }
            } else {
                d = makeDefer();
                requireDeferreds.push(d);
            }
            return d;
        }

        function makeErrback(d, name) {
            return function (err) {
                if (!d.rejected()) {
                    if (!err.dynaId) {
                        err.dynaId = 'id' + (errCount += 1);
                        err.requireModules = [name];
                    }
                    d.reject(err);
                }
            };
        }

        function waitForDep(depMap, relName, d, i) {
            d.depMax += 1;

            //Do the fail at the end to catch errors
            //in the then callback execution.
            callDep(depMap, relName).then(function (val) {
                d.depFinished(val, i);
            }, makeErrback(d, depMap.id)).fail(makeErrback(d, d.map.id));
        }

        function makeLoad(id) {
            var fromTextCalled;
            function load(value) {
                //Protect against older plugins that call load after
                //calling load.fromText
                if (!fromTextCalled) {
                    resolve(id, getDefer(id), value);
                }
            }

            load.error = function (err) {
                getDefer(id).reject(err);
            };

            load.fromText = function (text, textAlt) {
                /*jslint evil: true */
                var d = getDefer(id),
                    map = makeMap(makeMap(id).n),
                    plainId = map.id;

                fromTextCalled = true;

                //Set up the factory just to be a return of the value from
                //plainId.
                d.factory = function (p, val) {
                    return val;
                };

                //As of requirejs 2.1.0, support just passing the text, to reinforce
                //fromText only being called once per resource. Still
                //support old style of passing moduleName but discard
                //that moduleName in favor of the internal ref.
                if (textAlt) {
                    text = textAlt;
                }

                //Transfer any config to this other module.
                if (hasProp(config.config, id)) {
                    config.config[plainId] = config.config[id];
                }

                try {
                    req.exec(text);
                } catch (e) {
                    throw new Error('fromText eval for ' + plainId +
                                    ' failed: ' + e);
                }

                //Execute any waiting define created by the plainId
                takeQueue(plainId);

                //Mark this as a dependency for the plugin
                //resource
                d.deps = [map];
                waitForDep(map, null, d, d.deps.length);
            };

            return load;
        }

        load = typeof importScripts === 'function' ?
                function (map) {
                    var url = map.url;
                    if (urlFetched[url]) {
                        return;
                    }
                    urlFetched[url] = true;

                    //Ask for the deferred so loading is triggered.
                    //Do this before loading, since loading is sync.
                    getDefer(map.id);
                    importScripts(url);
                    takeQueue(map.id);
                } :
                function (map) {
                    var script,
                        id = map.id,
                        url = map.url;

                    if (urlFetched[url]) {
                        return;
                    }
                    urlFetched[url] = true;

                    script = document.createElement('script');
                    script.setAttribute('data-requiremodule', id);
                    script.type = config.scriptType || 'text/javascript';
                    script.charset = 'utf-8';
                    script.async = true;

                    loadCount += 1;

                    script.addEventListener('load', function () {
                        loadCount -= 1;
                        takeQueue(id);
                    }, false);
                    script.addEventListener('error', function () {
                        loadCount -= 1;
                        var err,
                            pathConfig = getOwn(config.paths, id),
                            d = getOwn(deferreds, id);
                        if (pathConfig && Array.isArray(pathConfig) && pathConfig.length > 1) {
                            script.parentNode.removeChild(script);
                            //Pop off the first array value, since it failed, and
                            //retry
                            pathConfig.shift();
                            d.map = makeMap(id);
                            load(d.map);
                        } else {
                            err = new Error('Load failed: ' + id + ': ' + script.src);
                            err.requireModules = [id];
                            getDefer(id).reject(err);
                        }
                    }, false);

                    script.src = url;

                    document.head.appendChild(script);
                };

        function callPlugin(plugin, map, relName) {
            plugin.load(map.n, makeRequire(relName), makeLoad(map.id), {});
        }

        callDep = function (map, relName) {
            var args,
                name = map.id,
                shim = config.shim[name];

            if (hasProp(waiting, name)) {
                args = waiting[name];
                delete waiting[name];
                main.apply(undef, args);
            } else if (!hasProp(deferreds, name)) {
                if (map.pr) {
                    return callDep(makeMap(map.pr)).then(function (plugin) {
                        //Redo map now that plugin is known to be loaded
                        var newMap = makeMap(name, relName, true),
                            newId = newMap.id,
                            shim = getOwn(config.shim, newId);

                        //Make sure to only call load once per resource. Many
                        //calls could have been queued waiting for plugin to load.
                        if (!hasProp(calledPlugin, newId)) {
                            calledPlugin[newId] = true;
                            if (shim && shim.deps) {
                                req(shim.deps, function () {
                                    callPlugin(plugin, newMap, relName);
                                });
                            } else {
                                callPlugin(plugin, newMap, relName);
                            }
                        }
                        return getDefer(newId).promise;
                    });
                } else if (shim && shim.deps) {
                    req(shim.deps, function () {
                        load(map);
                    });
                } else {
                    load(map);
                }
            }

            return getDefer(name).promise;
        };

        //Turns a plugin!resource to [plugin, resource]
        //with the plugin being undefined if the name
        //did not have a plugin prefix.
        function splitPrefix(name) {
            var prefix,
                index = name ? name.indexOf('!') : -1;
            if (index > -1) {
                prefix = name.substring(0, index);
                name = name.substring(index + 1, name.length);
            }
            return [prefix, name];
        }

        /**
         * Makes a name map, normalizing the name, and using a plugin
         * for normalization if necessary. Grabs a ref to plugin
         * too, as an optimization.
         */
        makeMap = function (name, relName, applyMap) {
            if (typeof name !== 'string') {
                return name;
            }

            var plugin, url, parts, prefix, result,
                cacheKey = name + ' & ' + (relName || '') + ' & ' + !!applyMap;

            parts = splitPrefix(name);
            prefix = parts[0];
            name = parts[1];

            if (!prefix && hasProp(mapCache, cacheKey)) {
                return mapCache[cacheKey];
            }

            if (prefix) {
                prefix = normalize(prefix, relName, applyMap);
                plugin = hasProp(defined, prefix) && defined[prefix];
            }

            //Normalize according
            if (prefix) {
                if (plugin && plugin.normalize) {
                    name = plugin.normalize(name, makeNormalize(relName));
                } else {
                    name = normalize(name, relName, applyMap);
                }
            } else {
                name = normalize(name, relName, applyMap);
                parts = splitPrefix(name);
                prefix = parts[0];
                name = parts[1];

                url = req.nameToUrl(name);
            }

            //Using ridiculous property names for space reasons
            result = {
                id: prefix ? prefix + '!' + name : name, //fullName
                n: name,
                pr: prefix,
                url: url
            };

            if (!prefix) {
                mapCache[cacheKey] = result;
            }

            return result;
        };

        function makeConfig(name) {
            return function () {
                return config.config[name] || {};
            };
        }

        handlers = {
            require: function (name) {
                return makeRequire(name);
            },
            exports: function (name) {
                var e = defined[name];
                if (typeof e !== 'undefined') {
                    return e;
                } else {
                    return (defined[name] = {});
                }
            },
            module: function (name) {
                return {
                    id: name,
                    uri: '',
                    exports: defined[name],
                    config: makeConfig(name)
                };
            }
        };

        function breakCycle(d, traced, processed) {
            var id = d.map.id;

            traced[id] = true;
            if (!d.finished() && d.deps) {
                d.deps.forEach(function (depMap) {
                    var depIndex,
                        depId = depMap.id,
                        dep = !hasProp(handlers, depId) && getDefer(depId);

                    //Only force things that have not completed
                    //being defined, so still in the registry,
                    //and only if it has not been matched up
                    //in the module already.
                    if (dep && !dep.finished() && !processed[depId]) {
                        if (hasProp(traced, depId)) {
                            d.deps.some(function (depMap, i) {
                                if (depMap.id === depId) {
                                    depIndex = i;
                                    return true;
                                }
                            });
                            d.depFinished(defined[depId], depIndex);
                        } else {
                            breakCycle(dep, traced, processed);
                        }
                    }
                });
            }
            processed[id] = true;
        }

        function check(d) {
            var err,
                notFinished = [],
                waitInterval = config.waitSeconds * 1000,
                //It is possible to disable the wait interval by using waitSeconds of 0.
                expired = waitInterval && (startTime + waitInterval) < (new Date()).getTime();

            if (loadCount === 0) {
                //If passed in a deferred, it is for a specific require call.
                //Could be a sync case that needs resolution right away.
                //Otherwise, if no deferred, means a nextTick and all
                //waiting require deferreds should be checked.
                if (d) {
                    if (!d.finished()) {
                        breakCycle(d, {}, {});
                    }
                } else if (requireDeferreds.length) {
                    requireDeferreds.forEach(function (d) {
                        breakCycle(d, {}, {});
                    });
                }
            }

            //If still waiting on loads, and the waiting load is something
            //other than a plugin resource, or there are still outstanding
            //scripts, then just try back later.
            if (expired) {
                //If wait time expired, throw error of unloaded modules.
                eachProp(deferreds, function (d) {
                    if (!d.finished()) {
                        notFinished.push(d.map.id);
                    }
                });
                err = new Error('Timeout for modules: ' + notFinished);
                err.requireModules = notFinished;
                req.onError(err);
            } else if (loadCount || requireDeferreds.length) {
                //Something is still waiting to load. Wait for it, but only
                //if a later check is not already scheduled.
                if (!checkingLater) {
                    checkingLater = true;
                    prim.nextTick(function () {
                        checkingLater = false;
                        check();
                    });
                }
            }
        }

        //Used to break out of the promise try/catch chains.
        function delayedError(e) {
            prim.nextTick(function () {
                if (!e.dynaId || !trackedErrors[e.dynaId]) {
                    trackedErrors[e.dynaId] = true;
                    req.onError(e);
                }
            });
        }

        main = function (name, deps, factory, errback, relName) {
            //Only allow main calling once per module.
            if (name && hasProp(calledDefine, name)) {
                return;
            }
            calledDefine[name] = true;

            var d = getDefer(name);

            //This module may not have dependencies
            if (deps && !Array.isArray(deps)) {
                //deps is not an array, so probably means
                //an object literal or factory function for
                //the value. Adjust args.
                factory = deps;
                deps = [];
            }

            d.promise.fail(errback || delayedError);

            //Use name if no relName
            relName = relName || name;

            //Call the factory to define the module, if necessary.
            if (typeof factory === 'function') {

                if (!deps.length && factory.length) {
                    //Remove comments from the callback string,
                    //look for require calls, and pull them into the dependencies,
                    //but only if there are function args.
                    factory
                        .toString()
                        .replace(commentRegExp, '')
                        .replace(cjsRequireRegExp, function (match, dep) {
                            deps.push(dep);
                        });

                    //May be a CommonJS thing even without require calls, but still
                    //could use exports, and module. Avoid doing exports and module
                    //work though if it just needs require.
                    //REQUIRES the function to expect the CommonJS variables in the
                    //order listed below.
                    deps = (factory.length === 1 ?
                            ['require'] :
                            ['require', 'exports', 'module']).concat(deps);
                }

                //Save info for use later.
                d.factory = factory;
                d.deps = deps;

                d.depending = true;
                deps.forEach(function (depName, i) {
                    var depMap;
                    deps[i] = depMap = makeMap(depName, relName, true);
                    depName = depMap.id;

                    //Fast path CommonJS standard dependencies.
                    if (depName === "require") {
                        d.values[i] = handlers.require(name);
                    } else if (depName === "exports") {
                        //CommonJS module spec 1.1
                        d.values[i] = handlers.exports(name);
                        d.usingExports = true;
                    } else if (depName === "module") {
                        //CommonJS module spec 1.1
                        d.values[i] = d.cjsModule = handlers.module(name);
                    } else {
                        waitForDep(depMap, relName, d, i);
                    }
                });
                d.depending = false;

                //Some modules just depend on the require, exports, modules, so
                //trigger their definition here if so.
                if (d.depCount === d.depMax) {
                    defineModule(d);
                }
            } else if (name) {
                //May just be an object definition for the module. Only
                //worry about defining if have a module name.
                resolve(name, d, factory);
            }

            startTime = (new Date()).getTime();

            if (!name) {
                check(d);
            }
        };

        req = makeRequire(null, true);

        /*
         * Just drops the config on the floor, but returns req in case
         * the config return value is used.
         */
        req.config = function (cfg) {
            if (cfg.context && cfg.context !== contextName) {
                return newContext(cfg.context).config(cfg);
            }

            //Since config changed, mapCache may not be valid any more.
            mapCache = {};

            //Make sure the baseUrl ends in a slash.
            if (cfg.baseUrl) {
                if (cfg.baseUrl.charAt(cfg.baseUrl.length - 1) !== '/') {
                    cfg.baseUrl += '/';
                }
            }

            //Save off the paths and packages since they require special processing,
            //they are additive.
            var primId,
                pkgs = config.pkgs,
                shim = config.shim,
                objs = {
                    paths: true,
                    config: true,
                    map: true
                };

            eachProp(cfg, function (value, prop) {
                if (objs[prop]) {
                    if (prop === 'map') {
                        if (!config.map) {
                            config.map = {};
                        }
                        mixin(config[prop], value, true, true);
                    } else {
                        mixin(config[prop], value, true);
                    }
                } else {
                    config[prop] = value;
                }
            });

            //Merge shim
            if (cfg.shim) {
                eachProp(cfg.shim, function (value, id) {
                    //Normalize the structure
                    if (Array.isArray(value)) {
                        value = {
                            deps: value
                        };
                    }
                    if ((value.exports || value.init) && !value.exportsFn) {
                        value.exportsFn = makeShimExports(value);
                    }
                    shim[id] = value;
                });
                config.shim = shim;
            }

            //Adjust packages if necessary.
            if (cfg.packages) {
                cfg.packages.forEach(function (pkgObj) {
                    var location;

                    pkgObj = typeof pkgObj === 'string' ? { name: pkgObj } : pkgObj;
                    location = pkgObj.location;

                    //Create a brand new object on pkgs, since currentPackages can
                    //be passed in again, and config.pkgs is the internal transformed
                    //state for all package configs.
                    pkgs[pkgObj.name] = {
                        name: pkgObj.name,
                        location: location || pkgObj.name,
                        //Remove leading dot in main, so main paths are normalized,
                        //and remove any trailing .js, since different package
                        //envs have different conventions: some use a module name,
                        //some use a file name.
                        main: (pkgObj.main || 'main')
                              .replace(currDirRegExp, '')
                              .replace(jsSuffixRegExp, '')
                    };
                });

                //Done with modifications, assing packages back to context config
                config.pkgs = pkgs;
            }

            //If want prim injected, inject it now.
            primId = config.definePrim;
            if (primId) {
                waiting[primId] = [primId, [], function () { return prim; }];
            }

            //If a deps array or a config callback is specified, then call
            //require with those args. This is useful when require is defined as a
            //config object before require.js is loaded.
            if (cfg.deps) {
                req(cfg.deps, cfg.callback);
            }

            return req;
        };

        req.onError = function (err) {
            throw err;
        };

        context = {
            id: contextName,
            defined: defined,
            waiting: waiting,
            config: config,
            deferreds: deferreds
        };

        contexts[contextName] = context;

        return req;
    }

    requirejs = topReq = newContext('_');

    if (typeof require !== 'function') {
        require = topReq;
    }

    /**
     * Executes the text. Normally just uses eval, but can be modified
     * to use a better, environment-specific call. Only used for transpiling
     * loader plugins, not for plain JS modules.
     * @param {String} text the text to execute/evaluate.
     */
    topReq.exec = function (text) {
        /*jslint evil: true */
        return eval(text);
    };

    topReq.contexts = contexts;

    define = function () {
        queue.push([].slice.call(arguments, 0));
    };

    define.amd = {
        jQuery: true
    };

    if (bootstrapConfig) {
        topReq.config(bootstrapConfig);
    }

    //data-main support.
    if (topReq.isBrowser) {
        dataMain = document.querySelectorAll('script[data-main]')[0];
        dataMain = dataMain && dataMain.getAttribute('data-main');
        if (dataMain) {
            //Strip off any trailing .js since dataMain is now
            //like a module name.
            dataMain = dataMain.replace(jsSuffixRegExp, '');
            topReq([dataMain]);
        }
    }
}(this));

define("alameda", function(){});

/*global define, setTimeout */
/*
 * Custom events lib. Notable features:
 *
 * - the module itself is an event emitter. Useful for "global" pub/sub.
 * - evt.mix can be used to mix in an event emitter into existing object.
 * - notification of listeners is done in a try/catch, so all listeners
 *   are notified even if one fails. Errors are thrown async via setTimeout
 *   so that all the listeners can be notified without escaping from the
 *   code via a throw within the listener group notification.
 * - new evt.Emitter() can be used to create a new instance of an
 *   event emitter.
 * - Uses "this" insternally, so always call object with the emitter args
 *
 */
define('evt',[],function() {

  var evt,
      slice = Array.prototype.slice,
      props = ['_events', '_pendingEvents', 'on', 'once', 'latest',
               'latestOnce', 'removeListener', 'emitWhenListener', 'emit'];

  function Emitter() {
    this._events = {};
    this._pendingEvents = {};
  }

  Emitter.prototype = {
    on: function(id, fn) {
      var listeners = this._events[id],
          pending = this._pendingEvents[id];
      if (!listeners) {
        listeners = this._events[id] = [];
      }
      listeners.push(fn);

      if (pending) {
        pending.forEach(function(args) {
          fn.apply(null, args);
        });
        delete this._pendingEvents[id];
      }
      return this;
    },

    once: function(id, fn) {
      var self = this,
          fired = false;
      function one() {
        if (fired)
          return;
        fired = true;
        fn.apply(null, arguments);
        // Remove at a further turn so that the event
        // forEach in emit does not get modified during
        // this turn.
        setTimeout(function() {
          self.removeListener(id, one);
        });
      }
      return this.on(id, one);
    },

    /**
     * Waits for a property on the object that has the event interface
     * to be available. That property MUST EVALUATE TO A TRUTHY VALUE.
     * hasOwnProperty is not used because many objects are created with
     * null placeholders to give a proper JS engine shape to them, and
     * this method should not trigger the listener for those cases.
     * If the property is already available, call the listener right
     * away. If not available right away, listens for an event name that
     * matches the property name.
     * @param  {String}   id property name.
     * @param  {Function} fn listener.
     */
    latest: function(id, fn) {
      if (this[id] && !this._pendingEvents[id]) {
        fn(this[id]);
      }
      this.on(id, fn);
    },

    /**
     * Same as latest, but only calls the listener once.
     * @param  {String}   id property name.
     * @param  {Function} fn listener.
     */
    latestOnce: function(id, fn) {
      if (this[id] && !this._pendingEvents[id])
        fn(this[id]);
      else
        this.once(id, fn);
    },

    removeListener: function(id, fn) {
      var i,
          listeners = this._events[id];
      if (listeners) {
        i = listeners.indexOf(fn);
        if (i !== -1) {
          listeners.splice(i, 1);
        }
        if (listeners.length === 0)
          delete this._events[id];
      }
    },

    /**
     * Like emit, but if no listeners yet, holds on
     * to the value until there is one. Any other
     * args after first one are passed to listeners.
     * @param  {String} id event ID.
     */
    emitWhenListener: function(id) {
      var listeners = this._events[id];
      if (listeners) {
        this.emit.apply(this, arguments);
      } else {
        if (!this._pendingEvents[id])
          this._pendingEvents[id] = [];
        this._pendingEvents[id].push(slice.call(arguments, 1));
      }
    },

    emit: function(id) {
      var args = slice.call(arguments, 1),
          listeners = this._events[id];
      if (listeners) {
        listeners.forEach(function(fn) {
          try {
            fn.apply(null, args);
          } catch (e) {
            // Throw at later turn so that other listeners
            // can complete. While this messes with the
            // stack for the error, continued operation is
            // valued more in this tradeoff.
            setTimeout(function() {
              throw e;
            });
          }
        });
      }
    }
  };

  evt = new Emitter();
  evt.Emitter = Emitter;

  evt.mix = function(obj) {
    var e = new Emitter();
    props.forEach(function(prop) {
      if (obj.hasOwnProperty(prop)) {
        throw new Error('Object already has a property "' + prop + '"');
      }
      obj[prop] = e[prop];
    });
    return obj;
  };

  return evt;
});

/*jshint browser: true */
/*globals define */

/**
 * Provides a wrapper over the mozApps.getSelf() API. Structured as an
 * evt emitter, with "latest" support, and "latest" is overridden so
 * that the call to getSelf() is delayed until the very first need
 * for it.
 *
 * This allows code to have a handle on this module, instead of making
 * the getSelf() call, and then only trigger the fetch via a call to
 * latest, delaying the work until it is actually needed. Once getSelf()
 * is fetched once, the result is reused.
 */
define('app_self',['require','exports','module','evt'],function(require, exports, module) {
  var evt = require('evt');

  var appSelf = evt.mix({}),
      mozApps = navigator.mozApps,
      oldLatest = appSelf.latest,
      loaded = false;

  if (!mozApps) {
    appSelf.self = {};
    loaded = true;
  }

  function loadSelf() {
    mozApps.getSelf().onsuccess = function(event) {
      loaded = true;
      var app = event.target.result;
      appSelf.self = app;
      appSelf.emit('self', appSelf.self);
    };
  }

  // Override latest to only do the work when something actually wants to
  // listen.
  appSelf.latest = function(id) {
    if (!loaded)
      loadSelf();

    if (id !== 'self')
      throw new Error(module.id + ' only supports "self" property');

    return oldLatest.apply(this, arguments);
  };

  return appSelf;
});

define('query_uri',[],function() {
  function queryURI(uri) {
    function addressesToArray(addresses) {
      if (!addresses)
        return [];
      addresses = addresses.split(/[,;]/);
      var addressesArray = addresses.filter(function notEmpty(addr) {
        return addr.trim() !== '';
      });
      return addressesArray;
    }
    var mailtoReg = /^mailto:(.*)/i;

    if (uri.match(mailtoReg)) {
      uri = uri.match(mailtoReg)[1];
      var parts = uri.split('?');
      var subjectReg = /(?:^|&)subject=([^\&]*)/i,
      bodyReg = /(?:^|&)body=([^\&]*)/i,
      ccReg = /(?:^|&)cc=([^\&]*)/i,
      bccReg = /(?:^|&)bcc=([^\&]*)/i;
      // Check if the 'to' field is set and properly decode it
      var to = parts[0] ? addressesToArray(decodeURIComponent(parts[0])) : [],
      subject,
      body,
      cc,
      bcc;

      if (parts.length == 2) {
        var data = parts[1];
        if (data.match(subjectReg))
          subject = decodeURIComponent(data.match(subjectReg)[1]);
        if (data.match(bodyReg))
          body = decodeURIComponent(data.match(bodyReg)[1]);
        if (data.match(ccReg))
          cc = addressesToArray(decodeURIComponent(data.match(ccReg)[1]));
        if (parts[1].match(bccReg))
          bcc = addressesToArray(decodeURIComponent(data.match(bccReg)[1]));
      }
        return [to, subject, body, cc, bcc];
    }

  }

  return queryURI;
});

/*global define */
define('query_string',[],function() {
  var queryString = {
    /**
     * Takes a querystring value, name1=value1&name2=value2... and converts
     * to an object with named properties.
     * @param  {String} value query string value.
     * @return {Object}
     */
    toObject: function toObject(value) {
      if (!value)
        return null;

      var result = {};

      value.split('&').forEach(function(keyValue) {
        var pair = keyValue.split('=');
        result[decodeURIComponent(pair[0])] = decodeURIComponent(pair[1]);
      });
      return result;
    },

    fromObject: function fromObject(object) {
      var result = '';
      Object.keys(object).forEach(function(key) {
        result += (result ? '&' : '') + encodeURIComponent(key) +
                 '=' + encodeURIComponent(object[key]);
      });
      return result;
    }
  };

  return queryString;
});

/*jshint browser: true */
/*global define, console */
define('app_messages',['require','app_self','evt','query_uri','query_string'],function(require) {

var appSelf = require('app_self'),
    evt = require('evt'),
    queryURI = require('query_uri'),
    queryString = require('query_string'),
    appMessages = evt.mix({}),
    pending = {},
    // htmlCacheRestorePendingMessage defined in html_cache_restore,
    // see comment for it.
    cachedList = (window.htmlCacheRestorePendingMessage &&
              window.htmlCacheRestorePendingMessage.length) ?
              window.htmlCacheRestorePendingMessage : [];

// Convert the cached list to named properties on pending.
cachedList.forEach(function(type) {
  pending[type] = true;
});

appMessages.hasPending = function(type) {
  return pending.hasOwnProperty(type) || (navigator.mozHasPendingMessage &&
                                          navigator.mozHasPendingMessage(type));
};

if ('mozSetMessageHandler' in navigator) {
  navigator.mozSetMessageHandler('activity', function onActivity(message) {
    var activityName = message.source.name,
        attachmentBlobs = message.source.data.blobs,
        attachmentNames = message.source.data.filenames,
        url = message.source.data.url || message.source.data.URI,
        urlParts = url ? queryURI(url) : [];

    // To assist in bug analysis, log the start of the activity here.
    console.log('activity!', activityName);

    var composeData = {
      to: urlParts[0],
      subject: urlParts[1],
      body: typeof urlParts[2] === 'string' ? urlParts[2] : null,
      cc: urlParts[3],
      bcc: urlParts[4],
      attachmentBlobs: attachmentBlobs,
      attachmentNames: attachmentNames
    };

    appMessages.emitWhenListener('activity',
                                 activityName, composeData, message);
  });

  navigator.mozSetMessageHandler('notification', function(msg) {
    if (!msg.clicked)
      return;

    appSelf.latest('self', function(app) {
      if (document.hidden)
        app.launch();
    });

    console.log('email got notification click: ' + msg);
    console.log(JSON.stringify(msg, null, '  '));

    // icon url parsing is a cray cray way to pass day day
    var data = queryString.toObject((msg.imageURL || '').split('#')[1]);
    appMessages.emitWhenListener('notification', data);
  });

  // Do not listen for navigator.mozSetMessageHandler('alarm') type, that is
  // only done in the back end's cronsync for now.
}
else {
  console.warn('Activity support disabled!');
}

return appMessages;

});

/*global document, console, setTimeout, define: true */

define('html_cache',['require','exports','module'],function(require, exports) {

/**
 * Version number for cache, allows expiring cache.
 * Set by build process, value must match the value
 * in html_cache_restore.js.
 */
var CACHE_VERSION = 'd67a19cc9f8e06b07527c5d9a3bf3b6d113dada2';

/**
 * Saves a JS object to document.cookie using JSON.stringify().
 * This method claims all cookie keys that have pattern
 * /htmlc(\d+)/
 */
exports.save = function htmlCacheSave(html) {
  html = encodeURIComponent(CACHE_VERSION + ':' + html);

  // Set to 20 years from now.
  var expiry = Date.now() + (20 * 365 * 24 * 60 * 60 * 1000);
  expiry = (new Date(expiry)).toUTCString();

  // Split string into segments.
  var index = 0;
  var endPoint = 0;
  var length = html.length;

  for (var i = 0; i < length; i = endPoint, index += 1) {
    // Max per-cookie length is around 4097 bytes for firefox.
    // Give some space for key and allow i18n chars, which may
    // take two bytes, end up with 2030. This page used
    // to test cookie limits: http://browsercookielimits.x64.me/
    endPoint = 2030 + i;
    if (endPoint > length) {
      endPoint = length;
    }

    document.cookie = 'htmlc' + index + '=' + html.substring(i, endPoint) +
                      '; expires=' + expiry;
  }

  // If previous cookie was bigger, clear out the other values,
  // to make sure they do not interfere later when reading and
  // reassembling. If the cache saved is too big, just clear it as
  // there will likely be cache corruption/partial, bad HTML saved
  // otherwise.
  var maxSegment = 40;
  if (index > 39) {
    index = 0;
    console.log('htmlCache.save TOO BIG. Removing all of it.');
  }
  for (i = index; i < maxSegment; i++) {
    document.cookie = 'htmlc' + i + '=; expires=' + expiry;
  }

  console.log('htmlCache.save: ' + html.length + ' in ' +
              (index) + ' segments');
};

/**
 * Serializes the node to storage. NOTE: it modifies the node tree,
 * so pass use cloneNode(true) on your node if you use it for other
 * things besides this call.
 * @param  {Node} node Node to serialize to storage.
 */
exports.saveFromNode = function saveFromNode(node) {
  // Make sure card will be visible in center of window. For example,
  // if user clicks on "search" or some other card is showing when
  // message list's atTop is received, then the node could be
  // off-screen when it is passed to this function.
  var cl = node.classList;
  cl.remove('before');
  cl.remove('after');
  cl.add('center');

  var html = node.outerHTML;
  exports.save(html);
};

/**
 * setTimeout ID used to track delayed save.
 */
var delayedSaveId = 0;

/**
 * Node to save on a delayed save.
 */
var delayedNode = '';

/**
 * Like saveFromNode, but on a timeout. NOTE: it modifies the node tree,
 * so pass use cloneNode(true) on your node if you use it for other
 * things besides this call.
 * @param  {Node} node Node to serialize to storage.
 */
exports.delayedSaveFromNode = function delayedSaveFromNode(node) {
  delayedNode = node;
  if (!delayedSaveId) {
    delayedSaveId = setTimeout(function() {
      delayedSaveId = 0;
      exports.saveFromNode(delayedNode);
      delayedNode = null;
    }, 500);
  }
};

});

define('l10n',{
  load: function(id, require, onload, config) {
    if (config.isBuild)
      return onload();

    require(['l10nbase', 'l10ndate'], function() {
      if (navigator.mozL10n.readyState === 'complete') {
        onload(navigator.mozL10n);
      } else {
        navigator.mozL10n.ready(function() {
          onload(navigator.mozL10n);
        });
      }
    });
  }
});

define('tmpl',['l10n!'], function(mozL10n) {
  var tmpl = {
    pluginBuilder: './tmpl_builder',

    toDom: function(text) {
        var temp = document.createElement('div');
        temp.innerHTML = text;
        var node = temp.children[0];
        mozL10n.translate(node);
        return node;
    },

    load: function(id, require, onload, config) {
      require(['text!' + id], function(text) {
        onload(tmpl.toDom(text));
      });
    }
  };

  return tmpl;
});

define('tmpl!cards/toaster.html',['tmpl'], function (tmpl) { return tmpl.toDom('<section role="status" class="banner customized collapsed">\n  <button class="toaster-cancel-btn header-left-btn">\n    <span class="icon icon-close"></span>\n  </button>\n  <p>Toaster Title</p>\n  <button data-l10n-id="toaster-undo" class="toaster-banner-undo"></button>\n  <button data-l10n-id="toaster-retry" class="toaster-banner-retry"></button>\n</section>'); });

/*global define */
define('folder_depth_classes',[],function() {

return [
  'fld-folder-depth0',
  'fld-folder-depth1',
  'fld-folder-depth2',
  'fld-folder-depth3',
  'fld-folder-depth4',
  'fld-folder-depth5',
  'fld-folder-depthmax'
];

});

/*
!! Warning !!
  This value selector is modified for email folder selection only.
  API and layout are changed because of the sub-folder indentation display.
  Please reference the original version selector in contact app before using.

How to:
  var prompt1 = new ValueSelector('Dummy title 1', [
    {
      label: 'Dummy element',
      callback: function() {
        alert('Define an action here!');
      }
    }
  ]);

  prompt1.addToList('Another button', function(){alert('Another action');});
  prompt1.show();
*/
/*jshint browser: true */
/*global alert, define */
define('value_selector',['require','folder_depth_classes','l10n!'],function(require) {

var FOLDER_DEPTH_CLASSES = require('folder_depth_classes'),
    mozL10n = require('l10n!');

function ValueSelector(title, list) {
  var init, show, hide, render, setTitle, emptyList, addToList,
      data, el;

  init = function() {
    var strPopup, body, section, btnCancel, cancelStr;

    // Model. By having dummy data in the model,
    // it make it easier for othe developers to catch up to speed
    data = {
      title: 'No Title',
      list: [
        {
          label: 'Dummy element',
          callback: function() {
            alert('Define an action here!');
          }
        }
      ]
    };

    body = document.body;
    cancelStr = mozL10n.get('message-multiedit-cancel');

    el = document.createElement('section');
    el.setAttribute('class', 'valueselector');
    el.setAttribute('role', 'region');

    strPopup = '<div role="dialog">';
    strPopup += '  <div class="center">';
    strPopup += '    <h3>No Title</h3>';
    strPopup += '    <ul>';
    strPopup += '      <li>';
    strPopup += '        <label class="pack-radio">';
    strPopup += '          <input type="radio" name="option">';
    strPopup += '          <span>Dummy element</span>';
    strPopup += '        </label>';
    strPopup += '      </li>';
    strPopup += '    </ul>';
    strPopup += '  </div>';
    strPopup += '  <menu>';
    strPopup += '    <button>' + cancelStr + '</button>';
    strPopup += '  </menu>';
    strPopup += '</div>';

    el.innerHTML += strPopup;
    body.appendChild(el);

    btnCancel = el.querySelector('button');
    btnCancel.addEventListener('click', function() {
      hide();
    });

    // Empty dummy data
    emptyList();

    // Apply optional actions while initializing
    if (typeof title === 'string') {
      setTitle(title);
    }

    if (Array.isArray(list)) {
      data.list = list;
    }
  };

  show = function() {
    render();
    el.classList.add('visible');
  };

  hide = function() {
    el.classList.remove('visible');
    emptyList();
  };

  render = function() {
    var title = el.querySelector('h3'),
        list = el.querySelector('ul');

    title.textContent = data.title;

    list.innerHTML = '';
    for (var i = 0; i < data.list.length; i++) {
      var li = document.createElement('li'),
          label = document.createElement('label'),
          input = document.createElement('input'),
          span = document.createElement('span'),
          text = document.createTextNode(data.list[i].label);

      input.setAttribute('type', 'radio');
      input.setAttribute('name', 'option');
      label.classList.add('pack-radio');
      label.appendChild(input);
      label.appendChild(span);
      label.appendChild(text);
      // Here we apply the folder-card's depth indentation to represent label.
      var depthIdx = data.list[i].depth;
      depthIdx = Math.min(FOLDER_DEPTH_CLASSES.length - 1, depthIdx);
      label.classList.add(FOLDER_DEPTH_CLASSES[depthIdx]);
      li.addEventListener('click', data.list[i].callback, false);
      li.appendChild(label);
      list.appendChild(li);
    }
  };

  setTitle = function(str) {
    data.title = str;
  };

  emptyList = function() {
    data.list = [];
  };

  addToList = function(label, depth, callback) {
    data.list.push({
      label: label,
      depth: depth,
      callback: callback
    });
  };

  init();

  return{
    init: init,
    show: show,
    hide: hide,
    setTitle: setTitle,
    addToList: addToList,
    List: list
  };
}

return ValueSelector;

});

/*
 * This file goes along with shared/style/input_areas.css
 * and is required to make the <button type="reset"> buttons work to clear
 * the form fields they are associated with.
 *
 * Bug 830127 should fix input_areas.css and move this JS functionality
 * to a shared JS file, so this file won't be in the email app for long.
 */
function hookupInputAreaResetButtons(e) {
  // This selector is from shared/style/input_areas.css
  var selector = 'form p input + button[type="reset"],' +
    'form p textarea + button[type="reset"]';
  var resetButtons = e.querySelectorAll(selector);
  for (var i = 0, n = resetButtons.length; i < n; i++) {
    resetButtons[i].addEventListener('mousedown', function(e) {
      e.preventDefault();   // Don't take focus from the input field
    });
    resetButtons[i].addEventListener('click', function(e) {
      e.target.previousElementSibling.value = ''; // Clear input field
      e.preventDefault();   // Don't reset the rest of the form.
    });
  }
}
;
define("input_areas", function(){});

/**
 * UI infrastructure code and utility code for the gaia email app.
 **/
/*jshint browser: true */
/*global define, console, hookupInputAreaResetButtons */
define('mail_common',['require','exports','module','l10n!','tmpl!./cards/toaster.html','value_selector','input_areas'],function(require, exports) {

var Cards, Toaster,
    mozL10n = require('l10n!'),
    toasterNode = require('tmpl!./cards/toaster.html'),
    ValueSelector = require('value_selector');

// Does not return a module value, just need it to make globals
require('input_areas');

function addClass(domNode, name) {
  if (domNode) {
    domNode.classList.add(name);
  }
}

function removeClass(domNode, name) {
  if (domNode) {
    domNode.classList.remove(name);
  }
}

function batchAddClass(domNode, searchClass, classToAdd) {
  var nodes = domNode.getElementsByClassName(searchClass);
  for (var i = 0; i < nodes.length; i++) {
    nodes[i].classList.add(classToAdd);
  }
}

function batchRemoveClass(domNode, searchClass, classToRemove) {
  var nodes = domNode.getElementsByClassName(searchClass);
  for (var i = 0; i < nodes.length; i++) {
    nodes[i].classList.remove(classToRemove);
  }
}

var MATCHED_TEXT_CLASS = 'highlight';

function appendMatchItemTo(matchItem, node) {
  var text = matchItem.text;
  var idx = 0;
  for (var iRun = 0; iRun <= matchItem.matchRuns.length; iRun++) {
    var run;
    if (iRun === matchItem.matchRuns.length)
      run = { start: text.length, length: 0 };
    else
      run = matchItem.matchRuns[iRun];

    // generate the un-highlighted span
    if (run.start > idx) {
      var tnode = document.createTextNode(text.substring(idx, run.start));
      node.appendChild(tnode);
    }

    if (!run.length)
      continue;
    var hspan = document.createElement('span');
    hspan.classList.add(MATCHED_TEXT_CLASS);
    hspan.textContent = text.substr(run.start, run.length);
    node.appendChild(hspan);
    idx = run.start + run.length;
  }
}

/**
 * Add an event listener on a container that, when an event is encounted on
 * a descendant, walks up the tree to find the immediate child of the container
 * and tells us what the click was on.
 */
function bindContainerHandler(containerNode, eventName, func) {
  containerNode.addEventListener(eventName, function(event) {
    var node = event.target;
    // bail if they clicked on the container and not a child...
    if (node === containerNode)
      return;
    while (node && node.parentNode !== containerNode) {
      node = node.parentNode;
    }
    func(node, event);
  }, false);
}

/**
 * Bind both 'click' and 'contextmenu' (synthetically created by b2g), plus
 * handling click suppression that is currently required because we still
 * see the click event.  We also suppress contextmenu's default event so that
 * we don't trigger the browser's right-click menu when operating in firefox.
 */
function bindContainerClickAndHold(containerNode, clickFunc, holdFunc) {
  // Rather than tracking suppressClick ourselves in here, we maintain the
  // state globally in Cards.  The rationale is that popup menus will be
  // triggered on contextmenu, which transfers responsibility of the click
  // event to the popup handling logic.  There is also no chance for multiple
  // contextmenu events overlapping (that we would consider reasonable).
  bindContainerHandler(
    containerNode, 'click',
    function(node, event) {
      if (Cards._suppressClick) {
        Cards._suppressClick = false;
        return;
      }
      clickFunc(node, event);
    });
  bindContainerHandler(
    containerNode, 'contextmenu',
    function(node, event) {
      // Always preventDefault, as this terminates processing of the click as a
      // drag event.
      event.preventDefault();
      // suppress the subsequent click if this was actually a left click
      if (event.button === 0) {
        Cards._suppressClick = true;
      }

      return holdFunc(node, event);
    });
}

/**
 * Fairly simple card abstraction with support for simple horizontal animated
 * transitions.  We are cribbing from deuxdrop's mobile UI's cards.js
 * implementation created jrburke.
 */
Cards = {
  /* @dictof[
   *   @key[name String]
   *   @value[@dict[
   *     @key[name String]{
   *       The name of the card, which should also be the name of the css class
   *       used for the card when 'card-' is prepended.
   *     }
   *     @key[modes @dictof[
   *       @key[modeName String]
   *       @value[modeDef @dict[
   *         @key[tray Boolean]{
   *           Should this card be displayed as a tray that leaves the edge of
   *           the adjacent card visible?  (The width of the edge being a
   *           value consistent across all cards.)
   *         }
   *       ]
   *     ]]
   *     @key[constructor Function]{
   *       The constructor to use to create an instance of the card.
   *     }
   *   ]]
   * ]
   */
  _cardDefs: {},

  /* @listof[@typedef[CardInstance @dict[
   *   @key[domNode]{
   *   }
   *   @key[cardDef]
   *   @key[modeDef]
   *   @key[left Number]{
   *     Left offset of the card in #cards.
   *   }
   *   @key[cardImpl]{
   *     The result of calling the card's constructor.
   *   }
   * ]]]{
   *   Existing cards, left-to-right, new cards getting pushed onto the right.
   * }
   */
  _cardStack: [],
  activeCardIndex: -1,
  /*
   * @oneof[null @listof[cardName modeName]]{
   *   If a lazy load is causing us to have to wait before we push a card, this
   *   is the type of card we are planning to push.  This is used by hasCard
   *   to avoid returning misleading answers while an async push is happening.
   * }
   */
  _pendingPush: null,

  /**
   * Cards can stack on top of each other, make sure the stacked set is
   * visible over the lower sets.
   */
  _zIndex: 0,

  /**
   * The DOM node that contains the _containerNode ("#cardContainer") and which
   * we inject popup and masking layers into.  The choice of doing the popup
   * stuff at this layer is arbitrary.
   */
  _rootNode: null,
  /**
   * The "#cardContainer" node which serves as the scroll container for the
   * contained _cardsNode ("#cards").  It is as wide as the viewport.
   */
  _containerNode: null,
  /**
   * The "#cards" node that holds the cards; it is as wide as all of the cards
   * it contains and has its left offset changed in order to change what card
   * is visible.
   */
  _cardsNode: null,

  /**
   * The DOM nodes that should be removed from their parent when our current
   * transition ends.
   */
  _animatingDeadDomNodes: [],

  /**
   * Tracks the number of transition events per card animation. Since each
   * animation ends up with two transitionend events since two cards are
   * moving, need to wait for the last one to be finished before doing
   * cleanup, like DOM removal.
   */
  _transitionCount: 0,

  /**
   * Annoying logic related to contextmenu event handling; search for the uses
   * for more info.
   */
  _suppressClick: false,
  /**
   * Is a tray card visible, suggesting that we need to intercept clicks in the
   * tray region so that we can transition back to the thing visible because of
   * the tray and avoid the click triggering that card's logic.
   */
  _trayActive: false,
  /**
   * Is a popup visible, suggesting that any click that is not on the popup
   * should be taken as a desire to close the popup?  This is not a boolean,
   * but rather info on the active popup.
   */
  _popupActive: null,
  /**
   * Are we eating all click events we see until we transition to the next
   * card (possibly due to a call to pushCard that has not yet occurred?).
   * Set by calling `eatEventsUntilNextCard`.
   */
  _eatingEventsUntilNextCard: false,

  /**
   * Initialize and bind ourselves to the DOM which should now be fully loaded.
   */
  _init: function() {
    this._rootNode = document.body;
    this._containerNode = document.getElementById('cardContainer');
    this._cardsNode = document.getElementById('cards');

    this._containerNode.appendChild(toasterNode);

    this._containerNode.addEventListener('click',
                                         this._onMaybeIntercept.bind(this),
                                         true);
    this._containerNode.addEventListener('contextmenu',
                                         this._onMaybeIntercept.bind(this),
                                         true);

    // XXX be more platform detecty. or just add more events. unless the
    // prefixes are already gone with webkit and opera?
    this._cardsNode.addEventListener('transitionend',
                                     this._onTransitionEnd.bind(this),
                                     false);
  },

  /**
   * If the tray is active and a click happens in the tray area, transition
   * back to the visible thing (which must be to our right currently.)
   */
  _onMaybeIntercept: function(event) {
    // Contextmenu-derived click suppression wants to gobble an explicitly
    // expected event, and so takes priority over other types of suppression.
    if (event.type === 'click' && this._suppressClick) {
      this._suppressClick = false;
      event.stopPropagation();
      return;
    }
    if (this._eatingEventsUntilNextCard) {
      event.stopPropagation();
      return;
    }
    if (this._popupActive) {
      event.stopPropagation();
      this._popupActive.close();
      return;
    }

    // Find the card containing the event target.
    var cardNode = event.target;
    for (cardNode = event.target; cardNode; cardNode = cardNode.parentNode) {
      if (cardNode.classList.contains('card'))
        break;
    }

    // If tray is active and the click is in the card that is after
    // current card (in the gutter), then just transition back to
    // that card.
    if (this._trayActive && cardNode && cardNode.classList.contains('after')) {
      event.stopPropagation();

      // Look for a card with a data-tray-target attribute
      var targetIndex = -1;
      this._cardStack.some(function(card, i) {
        if (card.domNode.hasAttribute('data-tray-target')) {
          targetIndex = i;
          return true;
        }
      });

      // Choose a default of one card ahead
      if (targetIndex === -1)
        targetIndex = this.activeCardIndex + 1;

      var indexDiff = targetIndex - (this.activeCardIndex + 1);
      if (indexDiff > 0) {
        this._afterTransitionAction = (function() {
          this.removeCardAndSuccessors(this._cardStack[0].domNode,
                                       'none', indexDiff);
          this.moveToCard(targetIndex, 'animate', 'forward');
        }.bind(this));
      }

      this.moveToCard(this.activeCardIndex + 1, 'animate', 'forward');
    }
  },

  /**
   * Called whenever the default card for the app should be inserted.
   * Override this method in the app. The app should call Card.pushCard
   * with the card of its choosing, and call the onPushed function passed
   * in to pushDefaultCard once the default card has been pushed. The
   * default card should be pushed with showMethod of 'none' so that
   * whatever the onPushed function does will work well with card nav.
   * @param  {Function} onPushed pass as the onPushed arg to pushCard.
   */
  pushDefaultCard: function(onPushed) {},

  defineCard: function(cardDef) {
    if (!cardDef.name)
      throw new Error('The card type needs a name');
    if (this._cardDefs.hasOwnProperty(cardDef.name))
      throw new Error('Duplicate card name: ' + cardDef.name);
    this._cardDefs[cardDef.name] = cardDef;

    // normalize the modes
    for (var modeName in cardDef.modes) {
      var mode = cardDef.modes[modeName];
      if (!mode.hasOwnProperty('tray'))
        mode.tray = false;
      mode.name = modeName;
    }
  },

  defineCardWithDefaultMode: function(name, defaultMode, constructor,
                                      templateNode) {
    var cardDef = {
      name: name,
      modes: {},
      constructor: constructor,
      templateNode: templateNode
    };
    cardDef.modes['default'] = defaultMode;
    this.defineCard(cardDef);
  },

  /**
   * Push a card onto the card-stack.
   */
  /* @args[
   *   @param[type]
   *   @param[mode String]{
   *   }
   *   @param[showMethod @oneof[
   *     @case['animate']{
   *       Perform an animated scrolling transition.
   *     }
   *     @case['immediate']{
   *       Immediately warp to the card without animation.
   *     }
   *     @case['none']{
   *       Don't touch the view at all.
   *     }
   *   ]]
   *   @param[args Object]{
   *     An arguments object to provide to the card's constructor when
   *     instantiating.
   *   }
   *   @param[placement #:optional @oneof[
   *     @case[undefined]{
   *       The card gets pushed onto the end of the stack.
   *     }
   *     @case['left']{
   *       The card gets inserted to the left of the current card.
   *     }
   *     @case['right']{
   *       The card gets inserted to the right of the current card.
   *     }
   *   }
   * ]
   */
  pushCard: function(type, mode, showMethod, args, placement) {
    var cardDef = this._cardDefs[type];
    var typePrefix = type.split('-')[0];

    args = args || {};

    if (!cardDef) {
      var cbArgs = Array.slice(arguments);
      this._pendingPush = [type, mode];

      // Only eat clicks if the card will be visibly displayed.
      if (showMethod !== 'none')
        this.eatEventsUntilNextCard();

      require(['cards/' + type], function() {
        this.pushCard.apply(this, cbArgs);
      }.bind(this));
      return;
    }

    this._pendingPush = null;

    var modeDef = cardDef.modes[mode];
    if (!modeDef)
      throw new Error('No such card mode: ' + mode);

    console.log('pushCard for type: ' + type);

    var domNode = args.cachedNode ?
                  args.cachedNode : cardDef.templateNode.cloneNode(true);

    domNode.setAttribute('data-type', type);
    domNode.setAttribute('data-mode', mode);

    var cardImpl = new cardDef.constructor(domNode, mode, args);
    var cardInst = {
      domNode: domNode,
      cardDef: cardDef,
      modeDef: modeDef,
      cardImpl: cardImpl
    };
    var cardIndex, insertBuddy;
    if (!placement) {
      cardIndex = this._cardStack.length;
      insertBuddy = null;
      domNode.classList.add(cardIndex === 0 ? 'before' : 'after');
    }
    else if (placement === 'left') {
      cardIndex = this.activeCardIndex++;
      insertBuddy = this._cardsNode.children[cardIndex];
      domNode.classList.add('before');
    }
    else if (placement === 'right') {
      cardIndex = this.activeCardIndex + 1;
      if (cardIndex >= this._cardStack.length)
        insertBuddy = null;
      else
        insertBuddy = this._cardsNode.children[cardIndex];
      domNode.classList.add('after');
    }
    this._cardStack.splice(cardIndex, 0, cardInst);

    if (!args.cachedNode)
      this._cardsNode.insertBefore(domNode, insertBuddy);

    // If the card has any <button type="reset"> buttons,
    // make them clear the field they're next to and not the entire form.
    // See input_areas.js and shared/style/input_areas.css.
    hookupInputAreaResetButtons(domNode);

    if ('postInsert' in cardImpl)
      cardImpl.postInsert();

    if (showMethod !== 'none') {
      // make sure the reflow sees the new node so that the animation
      // later is smooth.
      if (!args.cachedNode)
        domNode.clientWidth;

      this._showCard(cardIndex, showMethod, 'forward');
    }

    if (args.onPushed)
      args.onPushed(cardImpl);
  },

  _findCardUsingTypeAndMode: function(type, mode) {
    for (var i = 0; i < this._cardStack.length; i++) {
      var cardInst = this._cardStack[i];
      if (cardInst.cardDef.name === type &&
          cardInst.modeDef.name === mode) {
        return i;
      }
    }
  },

  _findCardUsingImpl: function(impl) {
    for (var i = 0; i < this._cardStack.length; i++) {
      var cardInst = this._cardStack[i];
      if (cardInst.cardImpl === impl)
        return i;
    }
  },

  _findCard: function(query, skipFail) {
    var result;
    if (Array.isArray(query))
      result = this._findCardUsingTypeAndMode(query[0], query[1], skipFail);
    else if (typeof(query) === 'number') // index number
      result = query;
    else
      result = this._findCardUsingImpl(query);

    if (result > -1)
      return result;
    else if (!skipFail)
      throw new Error('Unable to find card with query:', query);
    else
      // Returning undefined explicitly so that index comparisons, like
      // the one in hasCard, are correct.
      return undefined;
  },

  hasCard: function(query) {
    if (this._pendingPush && Array.isArray(query) && query.length === 2 &&
        this._pendingPush[0] === query[0] &&
        this._pendingPush[1] === query[1])
      return true;

    return this._findCard(query, true) > -1;
  },

  isVisible: function(cardImpl) {
    return !!(cardImpl.domNode &&
              cardImpl.domNode.classList.contains('center'));
  },

  findCardObject: function(query) {
    return this._cardStack[this._findCard(query)];
  },

  folderSelector: function(callback) {
    var self = this;

    require(['model', 'value_selector'], function(model) {
      // XXX: Unified folders will require us to make sure we get the folder
      //      list for the account the message originates from.
      if (!self.folderPrompt) {
        var selectorTitle = mozL10n.get('messages-folder-select');
        self.folderPrompt = new ValueSelector(selectorTitle);
      }

      model.latestOnce('foldersSlice', function(foldersSlice) {
        var folders = foldersSlice.items;
        for (var i = 0; i < folders.length; i++) {
          var folder = folders[i];
          self.folderPrompt.addToList(folder.name, folder.depth,
            function(folder) {
              return function() {
                self.folderPrompt.hide();
                callback(folder);
              };
            }(folder));

        }
        self.folderPrompt.show();
      });
    });
  },

  moveToCard: function(query, showMethod) {
    this._showCard(this._findCard(query), showMethod || 'animate');
  },

  tellCard: function(query, what) {
    var cardIndex = this._findCard(query),
        cardInst = this._cardStack[cardIndex];
    if (!('told' in cardInst.cardImpl))
      console.warn("Tried to tell a card that's not listening!", query, what);
    else
      cardInst.cardImpl.told(what);
  },

  /**
   * Create a mask that shows only the given node by creating 2 or 4 div's,
   * returning the container that holds those divs.  It's not clear if a single
   * div with some type of fancy clipping would be better.
   */
  _createMaskForNode: function(domNode, bounds) {
    var anchorIn = this._rootNode, cleanupDivs = [];
    var uiWidth = this._containerNode.offsetWidth,
        uiHeight = this._containerNode.offsetHeight;

    // inclusive pixel coverage
    function addMask(left, top, right, bottom) {
      var node = document.createElement('div');
      node.classList.add('popup-mask');
      node.style.left = left + 'px';
      node.style.top = top + 'px';
      node.style.width = (right - left + 1) + 'px';
      node.style.height = (bottom - top + 1) + 'px';
      cleanupDivs.push(node);
      anchorIn.appendChild(node);
    }
    if (bounds.left > 1)
      addMask(0, bounds.top, bounds.left - 1, bounds.bottom);
    if (bounds.top > 0)
      addMask(0, 0, uiWidth - 1, bounds.top - 1);
    if (bounds.right < uiWidth - 1)
      addMask(bounds.right + 1, bounds.top, uiWidth - 1, bounds.bottom);
    if (bounds.bottom < uiHeight - 1)
      addMask(0, bounds.bottom + 1, uiWidth - 1, uiHeight - 1);
    return function() {
      for (var i = 0; i < cleanupDivs.length; i++) {
        anchorIn.removeChild(cleanupDivs[i]);
      }
    };
  },

  /**
   * Remove the card identified by its DOM node and all the cards to its right.
   * Pass null to remove all of the cards! If cardDomNode passed, but there
   * are no cards before it, Cards.getDefaultCard is called to set up a before
   * card.
   */
  /* @args[
   *   @param[cardDomNode]{
   *     The DOM node that is the first card to remove; all of the cards to its
   *     right will also be removed.  If null is passed it is understood you
   *     want to remove all cards.
   *   }
   *   @param[showMethod @oneof[
   *     @case['animate']{
   *       Perform an animated scrolling transition.
   *     }
   *     @case['immediate']{
   *       Immediately warp to the card without animation.
   *     }
   *     @case['none']{
   *       Remove the nodes immediately, don't do anything about the view
   *       position.  You only want to do this if you are going to push one
   *       or more cards and the last card will use a transition of 'immediate'.
   *     }
   *   ]]
   *   @param[numCards #:optional Number]{
   *     The number of cards to remove.  If omitted, all the cards to the right
   *     of this card are removed as well.
   *   }
   *   @param[nextCardSpec #:optional]{
   *     If a showMethod is not 'none', the card to show after removal.
   *   }
   * ]
   */
  removeCardAndSuccessors: function(cardDomNode, showMethod, numCards,
                                    nextCardSpec) {
    if (!this._cardStack.length)
      return;

    if (cardDomNode && this._cardStack.length === 1) {
      // No card to go to when done, so ask for a default
      // card and continue work once it exists.
      return Cards.pushDefaultCard(function() {
        this.removeCardAndSuccessors(cardDomNode, showMethod, numCards,
                                    nextCardSpec);
      }.bind(this));
    }

    var firstIndex, iCard, cardInst;
    if (cardDomNode === undefined) {
      throw new Error('undefined is not a valid card spec!');
    }
    else if (cardDomNode === null) {
      firstIndex = 0;
      // reset the z-index to 0 since we may have cards in the stack that
      // adjusted the z-index (and we are definitively clearing all cards).
      this._zIndex = 0;
    }
    else {
      for (iCard = this._cardStack.length - 1; iCard >= 0; iCard--) {
        cardInst = this._cardStack[iCard];
        if (cardInst.domNode === cardDomNode) {
          firstIndex = iCard;
          break;
        }
      }
      if (firstIndex === undefined)
        throw new Error('No card represented by that DOM node');
    }
    if (!numCards)
      numCards = this._cardStack.length - firstIndex;

    if (showMethod !== 'none') {
      var nextCardIndex = null;
      if (nextCardSpec)
        nextCardIndex = this._findCard(nextCardSpec);
      else if (this._cardStack.length)
        nextCardIndex = Math.min(firstIndex - 1, this._cardStack.length - 1);

      this._showCard(nextCardIndex, showMethod, 'back');
    }

    // Update activeCardIndex if nodes were removed that would affect its
    // value.
    if (firstIndex <= this.activeCardIndex) {
      this.activeCardIndex -= numCards;
      if (this.activeCardIndex < -1) {
        this.activeCardIndex = -1;
      }
    }

    var deadCardInsts = this._cardStack.splice(
                          firstIndex, numCards);
    for (iCard = 0; iCard < deadCardInsts.length; iCard++) {
      cardInst = deadCardInsts[iCard];
      try {
        cardInst.cardImpl.die();
      }
      catch (ex) {
        console.warn('Problem cleaning up card:', ex, '\n', ex.stack);
      }
      switch (showMethod) {
        case 'animate':
        case 'immediate': // XXX handle properly
          this._animatingDeadDomNodes.push(cardInst.domNode);
          break;
        case 'none':
          cardInst.domNode.parentNode.removeChild(cardInst.domNode);
          break;
      }
    }
  },

  /**
   * Shortcut for removing all the cards
   */
  removeAllCards: function() {
    return this.removeCardAndSuccessors(null, 'none');
  },

  _showCard: function(cardIndex, showMethod, navDirection) {
    // Do not do anything if this is a show card for the current card.
    if (cardIndex === this.activeCardIndex) {
      return;
    }

    if (cardIndex > this._cardStack.length - 1) {
      // Some cards were removed, adjust.
      cardIndex = this._cardStack.length - 1;
    }
    if (this.activeCardIndex > this._cardStack.length - 1) {
      this.activeCardIndex = -1;
    }

    if (this.activeCardIndex === -1) {
      this.activeCardIndex = cardIndex === 0 ? cardIndex : cardIndex - 1;
    }

    var cardInst = (cardIndex !== null) ? this._cardStack[cardIndex] : null;
    var beginNode = this._cardStack[this.activeCardIndex].domNode;
    var endNode = this._cardStack[cardIndex].domNode;
    var isForward = navDirection === 'forward';

    if (this._cardStack.length === 1) {
      // Reset zIndex so that it does not grow ever higher when all but
      // one card are removed
      this._zIndex = 0;
    }

    // If going forward and it is an overlay node, then do not animate the
    // beginning node, it will just sit under the overlay.
    if (isForward && endNode.classList.contains('anim-overlay')) {
      beginNode = null;

      // anim-overlays are the transitions to new layers in the stack. If
      // starting a new one, it is forward movement and needs a new zIndex.
      // Otherwise, going back to
      this._zIndex += 10;
    }

    // If going back and the beginning node was an overlay, do not animate
    // the end node, since it should just be hidden under the overlay.
    if (beginNode && beginNode.classList.contains('anim-overlay')) {
      if (isForward) {
        // If a forward animation and overlay had a vertical transition,
        // disable it, use normal horizontal transition.
        if (showMethod !== 'immediate' &&
            beginNode.classList.contains('anim-vertical')) {
          removeClass(beginNode, 'anim-vertical');
          addClass(beginNode, 'disabled-anim-vertical');
        }
      } else {
        endNode = null;
        this._zIndex -= 10;
      }
    }

    // If the zindex is not zero, then in an overlay stack, adjust zindex
    // accordingly.
    if (endNode && isForward && this._zIndex) {
      endNode.style.zIndex = this._zIndex;
    }

    var cardsNode = this._cardsNode;

    if (showMethod === 'immediate') {
      addClass(beginNode, 'no-anim');
      addClass(endNode, 'no-anim');

      // make sure the reflow sees the transition is turned off.
      cardsNode.clientWidth;
      // explicitly clear since there will be no animation
      this._eatingEventsUntilNextCard = false;
    }
    else if (showMethod === 'none') {
      // do not set _eatingEventsUntilNextCard, but don't clear it either.
    }
    else {
      this._transitionCount = (beginNode && endNode) ? 2 : 1;
      this._eatingEventsUntilNextCard = true;
    }

    if (this.activeCardIndex === cardIndex) {
      // same node, no transition, just bootstrapping UI.
      removeClass(beginNode, 'before');
      removeClass(beginNode, 'after');
      addClass(beginNode, 'center');
    } else if (this.activeCardIndex > cardIndex) {
      // back
      removeClass(beginNode, 'center');
      addClass(beginNode, 'after');

      removeClass(endNode, 'before');
      addClass(endNode, 'center');
    } else {
      // forward
      removeClass(beginNode, 'center');
      addClass(beginNode, 'before');

      removeClass(endNode, 'after');
      addClass(endNode, 'center');
    }

    if (showMethod === 'immediate') {
      // make sure the instantaneous transition is seen before we turn
      // transitions back on.
      cardsNode.clientWidth;

      removeClass(beginNode, 'no-anim');
      removeClass(endNode, 'no-anim');

      if (cardInst && cardInst.onCardVisible)
        cardInst.onCardVisible();
    }

    // Hide toaster while active card index changed:
    Toaster.hide();

    this.activeCardIndex = cardIndex;
    if (cardInst)
      this._trayActive = cardInst.modeDef.tray;
  },

  _onTransitionEnd: function(event) {
    var activeCard = this._cardStack[this.activeCardIndex];
    // If no current card, this could be initial setup from cache, no valid
    // cards yet, so bail.
    if (!activeCard)
      return;

    // Multiple cards can animate, so there can be multiple transitionend
    // events. Only do the end work when all have finished animating.
    if (this._transitionCount > 0)
      this._transitionCount -= 1;

    if (this._transitionCount === 0) {
      if (this._eatingEventsUntilNextCard) {
        this._eatingEventsUntilNextCard = false;
      }
      if (this._animatingDeadDomNodes.length) {
        // Use a setTimeout to give the animation some space to settle.
        setTimeout(function() {
          this._animatingDeadDomNodes.forEach(function(domNode) {
            if (domNode.parentNode)
              domNode.parentNode.removeChild(domNode);
          });
          this._animatingDeadDomNodes = [];
        }.bind(this), 100);
      }

      // If an vertical overlay transition was was disabled, if
      // current node index is an overlay, enable it again.
      var endNode = activeCard.domNode;
      if (endNode.classList.contains('disabled-anim-vertical')) {
        removeClass(endNode, 'disabled-anim-vertical');
        addClass(endNode, 'anim-vertical');
      }

      // Popup toaster that pended for previous card view.
      var pendingToaster = Toaster.pendingStack.slice(-1)[0];
      if (pendingToaster) {
        pendingToaster();
        Toaster.pendingStack.pop();
      }

      // If any action to do at the end of transition trigger now.
      if (this._afterTransitionAction) {
        var afterTransitionAction = this._afterTransitionAction;
        this._afterTransitionAction = null;
        afterTransitionAction();
      }

      if (activeCard.cardImpl.onCardVisible)
        activeCard.cardImpl.onCardVisible();

      // If the card has next cards that can be preloaded, load them now.
      // Use of nextCards should be balanced with startup performance.
      // nextCards can result in smoother transitions to new cards on first
      // navigation to that new card type, but loading the extra module may
      // also compete with current card and data model performance.
      var nextCards = activeCard.cardImpl.nextCards;
      if (nextCards) {
        console.log('Preloading cards: ' + nextCards);
        require(nextCards.map(function(id) {
          return 'cards/' + id;
        }));
      }
    }
  },

  /**
   * Helper that causes (some) events targeted at our cards to be eaten until
   * we get to the next card.  The idea is to avoid bugs caused by the user
   * still being able to click things while our cards are transitioning or
   * while we are performing a (reliable) async wait before we actually initiate
   * a pushCard in response to user stimulus.
   *
   * This is automatically triggered when performing an animated transition;
   * other code should only call this in the async wait case mentioned above.
   *
   * For example, we don't want the user to have 2 message readers happening
   * at the same time because they managed to click on a second message before
   * the first reader got displayed.
   */
  eatEventsUntilNextCard: function() {
    this._eatingEventsUntilNextCard = true;
  },

  /**
   * Stop eating events, presumably because eatEventsUntilNextCard was used
   * as a hack for a known-fast async operation to avoid bugs (where we knew
   * full well that we weren't going to show a card).
   */
  stopEatingEvents: function() {
    this._eatingEventsUntilNextCard = false;
  },

  /**
   * If there are any cards on the deck right now, log an error and clear them
   * all out.  Our caller is strongly asserting that there should be no cards
   * and the presence of any indicates a bug.
   */
  assertNoCards: function() {
    if (this._cardStack.length)
      throw new Error('There are ' + this._cardStack.length + ' cards but' +
                      ' there should be ZERO');
  }
};

/**
 * Central tracker of poptart messages; specifically, ongoing message sends,
 * failed sends, and recently performed undoable mutations.
 */
Toaster = {
  get body() {
    delete this.body;
    return this.body =
           document.querySelector('section[role="status"]');
  },
  get text() {
    delete this.text;
    return this.text =
           document.querySelector('section[role="status"] p');
  },
  get undoBtn() {
    delete this.undoBtn;
    return this.undoBtn =
           document.querySelector('.toaster-banner-undo');
  },
  get retryBtn() {
    delete this.retryBtn;
    return this.retryBtn =
           document.querySelector('.toaster-banner-retry');
  },

  undoableOp: null,
  retryCallback: null,

  /**
   * Toaster timeout setting.
   */
  _timeout: 5000,
  /**
   * Toaster fadeout animation event handling.
   */
  _animationHandler: function() {
    this.body.addEventListener('transitionend', this, false);
    this.body.classList.add('fadeout');
  },
  /**
   * The list of cards that want to hear about what's up with the toaster.  For
   * now this will just be the message-list, but it might also be the
   * message-search card as well.  If it ends up being more, then we probably
   * want to rejigger things so we can just overlay stuff on most cards...
   */
  _listeners: [],

  pendingStack: [],

  /**
   * Tell toaster listeners about a mutation we just made.
   *
   * @param {Object} undoableOp undoable operation.
   * @param {Boolean} pending
   *   If true, indicates that we should wait to display this banner until we
   *   transition to the next card.  This is appropriate for things like
   *   deleting the message that is displayed on the current card (and which
   *   will be imminently closed).
   */
  logMutation: function(undoableOp, pending) {
    if (pending) {
      this.pendingStack.push(this.show.bind(this, 'undo', undoableOp));
    } else {
      this.show('undo', undoableOp);
    }
  },

  /**
   * Something failed that it makes sense to let the user explicitly trigger
   * a retry of!  For example, failure to synchronize.
   */
  logRetryable: function(retryStringId, retryCallback) {
    this.show('retry', retryStringId, retryCallback);
  },

  handleEvent: function(evt) {
    switch (evt.type) {
      case 'click' :
        var classList = evt.target.classList;
        if (classList.contains('toaster-banner-undo')) {
          this.undoableOp.undo();
          this.hide();
        } else if (classList.contains('toaster-banner-retry')) {
          if (this.retryCallback)
            this.retryCallback();
          this.hide();
        } else if (classList.contains('toaster-cancel-btn')) {
          this.hide();
        }
        break;
      case 'transitionend' :
        this.hide();
        break;
    }
  },

  show: function(type, operation, callback) {
    // Close previous toaster before showing the new one.
    if (!this.body.classList.contains('collapsed')) {
      this.hide();
    }

    var text, textId, showUndo = false;
    var undoBtn = this.body.querySelector('.toaster-banner-undo');
    if (type === 'undo') {
      this.undoableOp = operation;
      // There is no need to show toaster if affected message count < 1
      if (!this.undoableOp || this.undoableOp.affectedCount < 1) {
        return;
      }
      textId = 'toaster-message-' + this.undoableOp.operation;
      text = mozL10n.get(textId, { n: this.undoableOp.affectedCount });
      // https://bugzilla.mozilla.org/show_bug.cgi?id=804916
      // Remove undo email move/delete UI for V1.
      showUndo = (this.undoableOp.operation !== 'move' &&
                  this.undoableOp.operation !== 'delete');
    } else if (type === 'retry') {
      textId = 'toaster-retryable-' + operation;
      text = mozL10n.get(textId);
      this.retryCallback = callback;
    // XXX I assume this is for debug purposes?
    } else if (type === 'text') {
      text = operation;
    }

    if (type === 'undo' && showUndo)
      this.undoBtn.classList.remove('collapsed');
    else
      this.undoBtn.classList.add('collapsed');
    if (type === 'retry')
      this.retryBtn.classList.remove('collapsed');
    else
      this.retryBtn.classList.add('collapsed');

    this.body.title = type;
    this.text.textContent = text;
    this.body.addEventListener('click', this, false);
    this.body.classList.remove('collapsed');
    this.fadeTimeout = window.setTimeout(this._animationHandler.bind(this),
                                         this._timeout);
  },

  hide: function() {
    this.body.classList.add('collapsed');
    this.body.classList.remove('fadeout');
    window.clearTimeout(this.fadeTimeout);
    this.fadeTimeout = null;
    this.body.removeEventListener('click', this);
    this.body.removeEventListener('transitionend', this);

    // Clear operations:
    this.undoableOp = null;
    this.retryCallback = null;
  }
};

/**
 * Confirm dialog helper function. Display the dialog by providing dialog body
 * element and button id/handler function.
 *
 */
var ConfirmDialog = {
  dialog: null,
  show: function(dialog, confirm, cancel) {
    this.dialog = dialog;
    var formSubmit = function(evt) {
      this.hide();
      switch (evt.explicitOriginalTarget.id) {
        case confirm.id:
          confirm.handler();
          break;
        case cancel.id:
          if (cancel.handler)
            cancel.handler();
          break;
      }
      return false;
    };
    dialog.addEventListener('submit', formSubmit.bind(this));
    document.body.appendChild(dialog);
  },
  hide: function() {
    document.body.removeChild(this.dialog);
  }
};
////////////////////////////////////////////////////////////////////////////////
// Attachment Formatting Helpers

/**
 * Display a human-readable file size.  Currently we always display things in
 * kilobytes because we are targeting a mobile device and we want bigger sizes
 * (like megabytes) to be obviously large numbers.
 */
function prettyFileSize(sizeInBytes) {
  var kilos = Math.ceil(sizeInBytes / 1024);
  return mozL10n.get('attachment-size-kib', { kilobytes: kilos });
}

/**
 * Display a human-readable relative timestamp.
 */
function prettyDate(time, useCompactFormat) {
  var f = new mozL10n.DateTimeFormat();
  return f.fromNow(time, useCompactFormat);
}

(function() {
  var formatter = new mozL10n.DateTimeFormat();
  var updatePrettyDate = function updatePrettyDate() {
    var labels = document.querySelectorAll('[data-time]');
    var i = labels.length;
    while (i--) {
      labels[i].textContent = formatter.fromNow(
        labels[i].dataset.time,
        // the presence of the attribute is our indicator; not its value
        'compactFormat' in labels[i].dataset);
    }
  };
  var timer = setInterval(updatePrettyDate, 60 * 1000);

  window.addEventListener('message', function visibleAppUpdatePrettyDate(evt) {
    var data = evt.data;
    if (!data || (typeof(data) !== 'object') ||
        !('message' in data) || data.message !== 'visibilitychange')
      return;
    clearTimeout(timer);
    if (!data.hidden) {
      updatePrettyDate();
      timer = setInterval(updatePrettyDate, 60 * 1000);
    }
  });
})();

////////////////////////////////////////////////////////////////////////////////

/**
 * Class to handle form input navigation.
 *
 * If 'Enter' is hit, next input element will be focused,
 * and if the input element is the last one, trigger 'onLast' callback.
 *
 * options:
 *   {
 *     formElem: element,             // The form element
 *     checkFormValidity: function    // Function to check form validity
 *     onLast: function               // Callback when 'Enter' in the last input
 *   }
 */
function FormNavigation(options) {
  function extend(destination, source) {
    for (var property in source)
      destination[property] = source[property];
    return destination;
  }

  if (!options.formElem) {
    throw new Error('The form element should be defined.');
  }

  var self = this;
  this.options = extend({
    formElem: null,
    checkFormValidity: function checkFormValidity() {
      return self.options.formElem.checkValidity();
    },
    onLast: function() {}
  }, options);

  this.options.formElem.addEventListener('keypress',
    this.onKeyPress.bind(this));
}

FormNavigation.prototype = {
  onKeyPress: function formNav_onKeyPress(event) {
    if (event.keyCode === 13) {
      // If the user hit enter, focus the next form element, or, if the current
      // element is the last one and the form is valid, submit the form.
      var nextInput = this.focusNextInput(event);
      if (!nextInput && this.options.checkFormValidity()) {
        this.options.onLast();
      }
    }
  },

  focusNextInput: function formNav_focusNextInput(event) {
    var currentInput = event.target;
    var inputElems = this.options.formElem.getElementsByTagName('input');
    var currentInputFound = false;

    for (var i = 0; i < inputElems.length; i++) {
      var input = inputElems[i];
      if (currentInput === input) {
        currentInputFound = true;
        continue;
      } else if (!currentInputFound) {
        continue;
      }

      if (input.type === 'hidden' || input.type === 'button') {
        continue;
      }

      input.focus();
      if (document.activeElement !== input) {
        // We couldn't focus the element we wanted.  Try with the next one.
        continue;
      }
      return input;
    }

    // If we couldn't find anything to focus, just blur the initial element.
    currentInput.blur();
    return null;
  }
};

/**
 * Format the message subject appropriately.  This means ensuring that if the
 * subject is empty, we use a placeholder string instead.
 *
 * @param {DOMElement} subjectNode the DOM node for the message's subject.
 * @param {Object} message the message object.
 */
function displaySubject(subjectNode, message) {
  var subject = message.subject && message.subject.trim();
  if (subject) {
    subjectNode.textContent = subject;
    subjectNode.classList.remove('msg-no-subject');
  }
  else {
    subjectNode.textContent = mozL10n.get('message-no-subject');
    subjectNode.classList.add('msg-no-subject');
  }
}

exports.Cards = Cards;
exports.Toaster = Toaster;
exports.ConfirmDialog = ConfirmDialog;
exports.FormNavigation = FormNavigation;
exports.prettyDate = prettyDate;
exports.prettyFileSize = prettyFileSize;
exports.batchAddClass = batchAddClass;
exports.bindContainerClickAndHold = bindContainerClickAndHold;
exports.bindContainerHandler = bindContainerHandler;
exports.appendMatchItemTo = appendMatchItemTo;
exports.bindContainerHandler = bindContainerHandler;
exports.displaySubject = displaySubject;
});

/*global define, console */

define('model',['require','evt'],function(require) {
  var evt = require('evt');

  function dieOnFatalError(msg) {
    console.error('FATAL:', msg);
    throw new Error(msg);
  }

/**
 * Provides a front end to the API and slice objects returned from the API.
 * Since the UI right now is driven by a shared set of slices, this module
 * tracks those slices and creates events when they are changed. This means
 * the card modules do not need a direct reference to each other to change
 * the backing data for a card, and that card modules and app logic do not
 * need a hard, static dependency on the MailAPI object. This allows some
 * more flexible and decoupled loading scenarios. In particular, cards can
 * be created an inserted into the DOM without needing the back end to
 * complete its startup and initialization.
 *
 * It mixes in 'evt' capabilities, so it will be common to see model
 * used with 'latest' and 'latestOnce' to get the latest model data
 * whenever it loads.
 *
 * Down the road, it may make sense to have more than one model object
 * in play. At that point, it may make sense to morph this into a
 * constructor function and then have the card objects receive a model
 * instance property for their model reference.
 *
 * @type {Object}
 */
  var model = {
    firstRun: null,

    /**
    * acctsSlice event is fired when the property changes.
    * event: acctsSlice
    * @param {Object} the acctsSlice object.
    **/
    acctsSlice: null,

    /**
    * account event is fired when the property changes.
    * event: account
    * @param {Object} the account object.
    **/
    account: null,

    /**
    * foldersSlice event is fired when the property changes.
    * event: foldersSlice
    * @param {Object} the foldersSlice object.
    **/
    foldersSlice: null,

    /**
    * folder event is fired when the property changes.
    * event: folder
    * @param {Object} the folder object.
    **/
    folder: null,

    _callEmit: function(id) {
      this.emitWhenListener(id, this[id]);
    },

    inited: false,

    /**
     * Returns true if there is an account. Should only be
     * called after inited is true.
     */
    hasAccount: function() {
      return !!(model.acctsSlice &&
                model.acctsSlice.items &&
                model.acctsSlice.items.length);
    },

    /**
     * Given an account ID, get the account object. Only works once the
     * acctsSlice property is available. Use model.latestOnce to get a
     * handle on an acctsSlice property, then call this method.
     * @param  {String} id account ID.
     * @return {Object}    account object.
     */
    getAccount: function(id) {
      if (!model.acctsSlice || !model.acctsSlice.items)
        throw new Error('No acctsSlice available');

      var targetAccount;
      model.acctsSlice.items.some(function(account) {
        if (account.id === id)
          return !!(targetAccount = account);
      });

      return targetAccount;
    },

    /**
     * Call this to initialize the model. It can be called more than once
     * per the lifetime of an app. The usual use case for multiple calls
     * is when a new account has been added.
     * @param  {boolean} showLatest Choose the latest account in the
     * acctsSlice. Otherwise it choose the account marked as the default
     * account.
     */
    init: function(showLatest, callback) {
      // Set inited to false to indicate initialization is in progress.
      this.inited = false;
      require(['api'], function(MailAPI) {
        if (!this.api) {
          this.api = MailAPI;
          this._callEmit('api', this.api);
        }

        // If already initialized before, clear out previous state.
        this.die();

        var acctsSlice = this.acctsSlice = MailAPI.viewAccounts(false);
        acctsSlice.oncomplete = (function() {
          if (acctsSlice.items.length) {
            // For now, just use the first one; we do attempt to put unified
            // first so this should generally do the right thing.
            // XXX: Because we don't have unified account now, we should
            //      switch to the latest account which user just added.
            var account = showLatest ? acctsSlice.items.slice(-1)[0] :
                                       acctsSlice.defaultAccount;

            this.changeAccount(account, callback);
          }

          this.inited = true;
          this._callEmit('acctsSlice');
        }).bind(this);
      }.bind(this));
    },

    /**
     * Changes the current account tracked by the model. This results
     * in changes to the 'account', 'foldersSlice' and 'folder' properties.
     * @param  {Object}   account  the account object.
     * @param  {Function} callback function to call once the account and
     * related folder data has changed.
     */
    changeAccount: function(account, callback) {
      // Do not bother if account is the same.
      if (this.account && this.account.id === account.id) {
        if (callback)
          callback();
        return;
      }

      this._dieFolders();

      this.account = account;
      this._callEmit('account');

      var foldersSlice = this.api.viewFolders('account', account);
      foldersSlice.oncomplete = (function() {
        this.foldersSlice = foldersSlice;
        this.selectInbox(callback);
        this._callEmit('foldersSlice');
      }).bind(this);
    },

    /**
     * Given an account ID, change the current account to that account.
     * @param  {String} accountId
     * @return {Function} callback
     */
    changeAccountFromId: function(accountId, callback) {
      if (!this.acctsSlice || !this.acctsSlice.items.length)
        throw new Error('No accounts available');

      this.acctsSlice.items.some(function(account) {
        if (account.id === accountId) {
          this.changeAccount(account, callback);
          return true;
        }
      }.bind(this));
    },

    /**
     * Just changes the folder property tracked by the model.
     * Assumes the folder still belongs to the currently tracked
     * account.
     * @param  {Object} folder the folder object to use.
     */
    changeFolder: function(folder) {
      this.folder = folder;
      this._callEmit('folder');
    },

    /**
     * For the already loaded account and associated foldersSlice,
     * set the inbox as the tracked 'folder'.
     * @param  {Function} callback function called once the inbox
     * has been selected.
     */
    selectInbox: function(callback) {
      if (!this.foldersSlice)
        throw new Error('No foldersSlice available');

      var inboxFolder = this.foldersSlice.getFirstFolderWithType('inbox');
      if (!inboxFolder)
        dieOnFatalError('We have an account without an inbox!',
                        this.foldersSlice.items);

      if (this.folder && this.folder.id === inboxFolder.id) {
        if (callback)
          callback();
      } else {
        if (callback)
          this.once('folder', callback);

        this.changeFolder(inboxFolder);
      }
    },

    /**
     * Called by other code when it knows the current account
     * has received new inbox messages. Just triggers an
     * event with the count for now.
     * @param  {Object} accountUpdate update object from
     * sync.js accountResults object structure.
     */
    notifyInboxMessages: function(accountUpdate) {
      if (accountUpdate.id === this.account.id)
        model.emit('newInboxMessages', accountUpdate.count);
    },

    _dieFolders: function() {
      if (this.foldersSlice)
        this.foldersSlice.die();
      this.foldersSlice = null;

      this.folder = null;
    },

    die: function() {
      if (this.acctsSlice)
        this.acctsSlice.die();
      this.acctsSlice = null;
      this.account = null;

      this._dieFolders();
    }
  };

  return evt.mix(model);
});

/* -*- Mode: Java; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- /
/* vim: set shiftwidth=2 tabstop=2 autoindent cindent expandtab: */



/**
 * Keeping a reference on all active notifications to avoid weird GC issues.
 * See https://bugzilla.mozilla.org/show_bug.cgi?id=755402
 */

var NotificationHelper = {
  _referencesArray: [],

  getIconURI: function nc_getIconURI(app, entryPoint) {
    var icons = app.manifest.icons;

    if (entryPoint) {
      icons = app.manifest.entry_points[entryPoint].icons;
    }

    if (!icons)
      return null;

    var sizes = Object.keys(icons).map(function parse(str) {
      return parseInt(str, 10);
    });
    sizes.sort(function(x, y) { return y - x; });

    var HVGA = document.documentElement.clientWidth < 480;
    var index = sizes[HVGA ? sizes.length - 1 : 0];
    return app.installOrigin + icons[index];
  },

  send: function nc_send(title, body, icon, clickCB, closeCB) {
    if (!('mozNotification' in navigator))
      return;

    var notification = navigator.mozNotification.createNotification(title,
                                                                    body, icon);

    notification.onclick = (function() {
      if (clickCB)
        clickCB();

      this._forget(notification);
    }).bind(this);

    notification.onclose = (function() {
      if (closeCB)
        closeCB();

      this._forget(notification);
    }).bind(this);

    notification.show();
    this._keep(notification);
  },

  _keep: function nc_keep(notification) {
    this._referencesArray.push(notification);
  },
  _forget: function nc_forget(notification) {
    this._referencesArray.splice(
      this._referencesArray.indexOf(notification), 1
    );
  }
};


define("shared/js/notification_helper", (function (global) {
    return function () {
        var ret, fn;
        return ret || global.NotificationHelper;
    };
}(this)));

/*jshint browser: true */
/*global define, console, plog, Notification */
define('sync',['require','app_self','evt','model','l10n!','shared/js/notification_helper','query_string'],function(require) {

  var appSelf = require('app_self'),
      evt = require('evt'),
      model = require('model'),
      mozL10n = require('l10n!'),
      notificationHelper = require('shared/js/notification_helper'),
      fromObject = require('query_string').fromObject;

  model.latestOnce('api', function(api) {
    var hasBeenVisible = !document.hidden,
        waitingOnCron = {};

    // Let the back end know the app is interactive, not just
    // a quick sync and shutdown case, so that it knows it can
    // do extra work.
    if (hasBeenVisible) {
      api.setInteractive();
    }

    // If the page is ever not hidden, then do not close it later.
    document.addEventListener('visibilitychange',
      function onVisibilityChange() {
        if (!document.hidden) {
          hasBeenVisible = true;
          api.setInteractive();
        }
    }, false);

    // Creates a string key from an array of string IDs. Uses a space
    // separator since that cannot show up in an ID.
    function makeAccountKey(accountIds) {
      return 'id' + accountIds.join(' ');
    }

    var sendNotification;
    if (typeof Notification === 'undefined') {
      console.log('email: notifications not available');
      sendNotification = function() {};
    } else {
      sendNotification = function(notificationId, title, body, iconUrl) {
        console.log('Notification sent for ' + notificationId);
        notificationHelper.send(title, body, iconUrl);

        /*
        // TODO: explore this pathway for notification revocation, by using
        // the "tag" on the notification options. Does not work right now --
        // notification is triggered, but clicking on it generates an error
        // in system app.
        if (Notification.permission !== 'granted') {
          console.log('email: notification skipped, permission: ' +
                      Notification.permission);
          return;
        }

        //TODO: consider setting dir and lang
        //https://developer.mozilla.org/en-US/docs/Web/API/notification
        var notification = new Notification(title, {
          body: body,
          icon: iconUrl,
          tag: notificationId
        });
        */
      };
    }

    api.oncronsyncstart = function(accountIds) {
      console.log('email oncronsyncstart: ' + accountIds);
      var accountKey = makeAccountKey(accountIds);
      waitingOnCron[accountKey] = true;
    };

    function makeNotificationDesc(infos) {
      // For now, just list who the mails are from, as there is no formatting
      // possibilities in the existing notifications for the description
      // section. Even new lines do not seem to work.
      var froms = [];

      infos.forEach(function(info) {
        if (froms.indexOf(info.from) === -1)
          froms.push(info.from);
      });
      return froms.join(', ');
    }

    /*
    accountsResults is an object with the following structure:
      accountIds: array of string account IDs.
      updates: array of objects includes properties:
        id: accountId,
        name: account name,
        count: number of new messages total
        latestMessageInfos: array of latest message info objects,
        with properties:
          - from
          - subject
          - accountId
          - messageSuid
     */
    api.oncronsyncstop = function(accountsResults) {
      console.log('email oncronsyncstop: ' + accountsResults.accountIds);

      appSelf.latest('self', function(app) {

        model.latestOnce('account', function(currentAccount) {
          var iconUrl = notificationHelper.getIconURI(app);
          if (accountsResults.updates) {
            accountsResults.updates.forEach(function(result) {
              // If the current account is being shown, then just send
              // an update to the model to indicate new messages, as
              // the notification will happen within the app for that
              // case.
              if (currentAccount.id === result.id && !document.hidden) {
                model.notifyInboxMessages(result);
                return;
              }

              // If this account does not want notifications of new messages
              // stop doing work.
              if (!model.getAccount(result.id).notifyOnNew)
                return;

              var dataString;
              if (navigator.mozNotification) {
                if (result.count > 1) {
                  dataString = fromObject({
                    type: 'message_list',
                    accountId: result.id
                  });

                  sendNotification(
                    result.id,
                    mozL10n.get('new-emails-notify', {
                      n: result.count,
                      accountName: result.address
                    }),
                    makeNotificationDesc(result.latestMessageInfos),
                    iconUrl + '#' + dataString
                  );
                } else {
                  result.latestMessageInfos.forEach(function(info) {
                      dataString = fromObject({
                        type: 'message_reader',
                        accountId: info.accountId,
                        messageSuid: info.messageSuid
                      });

                    sendNotification(
                      result.id,
                      info.subject,
                      info.from,
                      iconUrl + '#' + dataString
                    );
                  });
                }
              }
            });
          }
        });

        evt.emit('cronSyncStop', accountsResults.accountIds);

        // Mark this accountId set as no longer waiting.
        var accountKey = makeAccountKey(accountsResults.accountIds);
        waitingOnCron[accountKey] = false;
        var stillWaiting = Object.keys(waitingOnCron).some(function(key) {
          return !!waitingOnCron[key];
        });

        if (!hasBeenVisible && !stillWaiting) {
          var msg = 'mail sync complete, closing mail app';
          if (typeof plog === 'function')
            plog(msg);
          else
            console.log(msg);

          window.close();
        }
      });
    };

  });
});

/*jshint browser: true */
/*globals define, console */

define('wake_locks',['require','evt'],function(require) {
  var lockTimeouts = {},
      evt = require('evt'),
      allLocks = {},

      // Only allow keeping the locks for a maximum of 45 seconds.
      // This is to prevent a long, problematic sync from consuming
      // all of the battery power in the phone. A more sophisticated
      // method may be to adjust the size of the timeout based on
      // past performance, but that would mean keeping a persistent
      // log of attempts. This naive approach just tries to catch the
      // most likely set of failures: just a temporary really bad
      // cell network situation that once the next sync happens, the
      // issue is resolved.
      maxLockInterval = 45000;

  function clearLocks(accountKey) {
    console.log('email: clearing wake locks for "' + accountKey + '"');

    // Clear timer
    var lockTimeoutId = lockTimeouts[accountKey];
    if (lockTimeoutId)
      clearTimeout(lockTimeoutId);
    lockTimeouts[accountKey] = 0;

    // Clear the locks
    var locks = allLocks[accountKey];
    allLocks[accountKey] = null;
    if (locks) {
      locks.forEach(function(lock) {
        lock.unlock();
      });
    }
  }

  // Creates a string key from an array of string IDs. Uses a space
  // separator since that cannot show up in an ID.
  function makeAccountKey(accountIds) {
    return 'id' + accountIds.join(' ');
  }

  function onCronStop(accountIds) {
    clearLocks(makeAccountKey(accountIds));
  }

  evt.on('cronSyncWakeLocks', function(accountKey, locks) {
    if (lockTimeouts[accountKey]) {
      // Only support one set of locks. Better to err on the side of
      // saving the battery and not continue syncing vs supporting a
      // pathologic error that leads to a compound set of locks but
      // end up with more syncs completing.
      clearLocks(accountKey);
    }

    allLocks[accountKey] = locks;

    lockTimeouts[accountKey] = setTimeout(clearLocks.bind(null, accountKey),
                                          maxLockInterval);
  });

  evt.on('cronSyncStop', onCronStop);
});

// when running in B2G, send output to the console, ANSI-style
if ('mozTCPSocket' in window.navigator) {
  function consoleHelper() {
    var msg = arguments[0] + ':';
    for (var i = 1; i < arguments.length; i++) {
      msg += ' ' + arguments[i];
    }
    msg += '\x1b[0m\n';
    dump(msg);
  }
  window.console = {
    log: consoleHelper.bind(null, '\x1b[32mLOG'),
    error: consoleHelper.bind(null, '\x1b[31mERR'),
    info: consoleHelper.bind(null, '\x1b[36mINF'),
    warn: consoleHelper.bind(null, '\x1b[33mWAR')
  };
}
window.onerror = function errHandler(msg, url, line) {
  console.error('onerror reporting:', msg, '@', url, ':', line);
  return false;
};


define("console_hook", function(){});

define('tmpl!cards/message_list.html',['tmpl'], function (tmpl) { return tmpl.toDom('<!-- Lists the messages in a folder -->\n<div class="card-message-list card" data-tray-target>\n  <!-- Non-search header -->\n  <section class="msg-list-header msg-nonsearch-only" role="region">\n    <header>\n      <a href="#" class="msg-folder-list-btn">\n        <span class="icon icon-menu">menu</span>\n      </a>\n      <menu type="toolbar">\n        <a href="#" class="msg-compose-btn">\n          <span class="icon icon-compose">compose</span>\n        </a>\n      </menu>\n      <h1 class="msg-list-header-folder-label header-label"></h1>\n    </header>\n  </section>\n  <!-- Multi-edit state header -->\n  <section class="msg-listedit-header skin-dark collapsed" role="region">\n    <header>\n      <a href="#" class="msg-listedit-cancel-btn">\n        <span class="icon icon-close"></span>\n      </a>\n      <h1 class="msg-listedit-header-label"></h1>\n    </header>\n  </section>\n  <!-- Search header -->\n  <section role="region"\n           class="msg-search-header msg-search-only">\n    <header>\n      <a href="#" class="msg-search-cancel">\n        <span class="icon icon-close"\n              data-l10n-id="message-search-cancel-accessible"></span>\n      </a>\n      <form>\n        <input type="text" required="required" class="msg-search-text"\n               data-l10n-id="message-search-input" />\n        <button type="reset" data-l10n-id="form-clear-input"></button>\n      </form>\n    </header>\n    <!-- Search filter switcher -->\n    <header class="msg-search-controls-bar">\n      <ul role="tablist" class="filter" data-type="filter" data-items="5">\n        <li role="tab" class="msg-search-from msg-search-filter"\n            data-filter="author">\n          <a data-l10n-id="message-search-from">FroM</a></li>\n        <li role="tab" class="msg-search-to msg-search-filter"\n            data-filter="recipients">\n          <a data-l10n-id="message-search-to">tO</a></li>\n        <li role="tab" class="msg-search-subject msg-search-filter"\n             data-filter="subject">\n          <a data-l10n-id="message-search-subject">SubjecT</a>\n        </li>\n        <li role="tab" class="msg-search-body msg-search-filter"\n             data-filter="body">\n          <a data-l10n-id="message-search-body">BodY</a></li>\n        <li role="tab" class="msg-search-body msg-search-filter"\n            data-filter="all" aria-selected>\n          <a data-l10n-id="message-search-all">AlL</a></li>\n      </ul>\n    </header>\n  </section>\n  <!-- Scroll region -->\n  <div class="msg-list-scrollouter">\n    <!-- exists so we can force a minimum height -->\n    <div class="msg-list-scrollinner">\n      <!-- The search textbox hides under the lip of the messages.\n           As soon as any typing happens in it, we push the search\n           controls card. -->\n      <div class="msg-search-tease-bar msg-nonsearch-only">\n        <input class="msg-search-text-tease" type="text"\n               data-l10n-id="message-search-input" />\n      </div>\n      <div class="msg-messages-container">\n      </div>\n      <!-- maintain vertical space for the syncing/sync more div\'s\n           regardless of their displayed status so we don\'t scroll them\n           out of the way -->\n      <div class="msg-messages-sync-container">\n        <p class="msg-messages-syncing collapsed">\n          <span data-l10n-id="messages-syncing">Message loadinG</span>\n        </p>\n        <p class="msg-messages-sync-more collapsed">\n          <span data-l10n-id="messages-sync-more">SynC MorE</span>\n        </p>\n      </div>\n      <div class="bottom-toolbar-spacer"></div>\n    </div>\n  </div>\n  <!-- New email notification bar -->\n  <div class="msg-list-topbar collapsed"></div>\n  <!-- Conveys background send, plus undo-able recent actions -->\n  <div class="msg-activity-infobar hidden">\n  </div>\n  <!-- Toolbar for non-multi-edit state -->\n  <div class="msg-list-action-toolbar bottom-toolbar">\n    <button class="msg-refresh-btn bottom-btn msg-nonsearch-only"\n            data-state="synchronized"></button>\n    <button class="msg-search-btn bottom-btn msg-nonsearch-only"></button>\n    <button class="msg-edit-btn bottom-btn"></button>\n  </div>\n  <!-- Toolbar for multi-edit state -->\n  <div class="msg-listedit-action-toolbar bottom-edit-toolbar bottom-toolbar collapsed">\n    <button class="msg-delete-btn bottom-btn"></button>\n    <button class="msg-star-btn bottom-btn"></button>\n    <button class="msg-mark-read-btn bottom-btn"></button>\n    <button class="msg-move-btn bottom-btn"></button>\n  </div>\n  <div class="msg-list-empty-container collapsed">\n    <p class="msg-list-empty-message-text" data-l10n-id="messages-folder-empty">No messagE</p>\n  </div>\n</div>\n'); });

define('tmpl!cards/msg/header_item.html',['tmpl'], function (tmpl) { return tmpl.toDom('<a class="msg-header-item">\n  <label class="pack-checkbox negative">\n    <input type="checkbox"><span></span>\n  </label>\n  <div class="msg-header-unread-section"></div>\n  <div class="msg-header-details-section">\n    <span class="msg-header-author-and-date">\n      <span class="msg-header-author"></span>\n      <span class="msg-header-date"></span>\n    </span><span class="msg-header-subject"></span>\n    <span class="msg-header-snippet"></span>\n  </div><div class="msg-header-icons-section">\n    <span class="msg-header-star"></span>\n    <span class="msg-header-attachments"></span>\n  </div><div class="msg-header-avatar-section">\n  </div></a>\n'); });

define('tmpl!cards/msg/delete_confirm.html',['tmpl'], function (tmpl) { return tmpl.toDom('<form role="dialog" class="msg-delete-confirm" data-type="confirm">\n  <section>\n    <h1 data-l10n-id="confirm-dialog-title">ConfirmatioN</h1>\n    <p><span data-l10n-id="message-edit-delete-confirm"></span></p>\n  </section>\n  <menu>\n    <button id="msg-delete-cancel" data-l10n-id="message-multiedit-cancel">CanceL</button>\n    <button id="msg-delete-ok" class="danger" data-l10n-id="message-edit-menu-delete">OK</button>\n  </menu>\n</form>'); });


/**
 * @fileoverview This file provides a MessageListTopbar which is
 *     a little notification bar that tells the user
 *     how many new emails they've received after a sync.
 */

define('message_list_topbar',['l10n!'], function(mozL10n) {
/**
 * @constructor
 * @param {Element} scrollContainer Element containing folder messages.
 * @param {number} newEmailCount The number of new messages we received.
 */
function MessageListTopbar(scrollContainer, newEmailCount) {
  this._scrollContainer = scrollContainer;
  this._newEmailCount = newEmailCount;
}


/**
 * @const {string}
 */
MessageListTopbar.CLASS_NAME = 'msg-list-topbar';


/**
 * Number of milliseconds after which the status bar should disappear.
 * @const {number}
 */
MessageListTopbar.DISAPPEARS_AFTER_MILLIS = 5000;


MessageListTopbar.prototype = {
  /**
   * @type {Element}
   * @private
   */
  _el: null,


  /**
   * @type {Element}
   * @private
   */
  _scrollContainer: null,


  /**
   * @type {number}
   * @private
   */
  _newEmailCount: 0,


  /**
   * Update the div with the correct new email count and
   * listen to it for mouse clicks.
   * @param {Element} el The div we'll decorate.
   */
  decorate: function(el) {
    el.addEventListener('click', this._onclick.bind(this));
    this._el = el;
    this.updateNewEmailCount();
    return this._el;
  },


  /**
   * Show our element and set a timer to destroy it after
   * DISAPPEARS_AFTER_MILLIS.
   */
  render: function() {
    this._el.classList.remove('collapsed');
    setTimeout(
        this.destroy.bind(this),
        MessageListTopbar.DISAPPEARS_AFTER_MILLIS
    );
  },


  /**
   * Release the element and any event listeners and cleanup our data.
   */
  destroy: function() {
    if (this._el) {
      this._el.removeEventListener('click', this._onclick.bind(this));
      this._el.classList.add('collapsed');
      this._el.textContent = '';
      this._el = null;
    }
  },


  /**
   * @return {Element} Our underlying element.
   */
  getElement: function() {
    return this._el;
  },


  /**
   * @param {number} newEmailCount Optional number of new messages we received.
   */
  updateNewEmailCount: function(newEmailCount) {
    if (newEmailCount !== undefined) {
      this._newEmailCount += newEmailCount;
    }

    if (this._el !== null) {
      this._el.textContent =
          mozL10n.get('new-emails', { n: this._newEmailCount });
    }
  },


  /**
   * @type {Event} evt Some mouseclick event.
   */
  _onclick: function(evt) {
    this.destroy();

    var scrollTop = this._scrollContainer.scrollTop;
    var dest = this._getScrollDestination();
    if (scrollTop <= dest) {
      return;
    }

    this._scrollUp(this._scrollContainer, dest, 0, 50);
  },


  /**
   * Move the element up to the specified position over time by increments.
   * @param {Element} el Some element to scroll.
   * @param {number} dest The eventual scrollTop value.
   * @param {number} timeout How long to wait between each time.
   * @param {number} inc How far to scroll each time.
   * @private
   */
  _scrollUp: function(el, dest, timeout, inc) {
    var next = el.scrollTop - inc;
    if (dest >= next) {
      // This is the last scroll.
      el.scrollTop = dest;
      return;
    }

    el.scrollTop = next;
    setTimeout(this._scrollUp.bind(this, el, dest, timeout, inc), timeout);
  },


  /**
   * @return {number} The point where we should scroll to calculated from
   *     the search box height.
   * @private
   */
  _getScrollDestination: function() {
    var searchBar =
        document.getElementsByClassName('msg-search-tease-bar')[0];
    return searchBar.offsetHeight;
  }
};

return MessageListTopbar;
});


/*jshint browser: true */
/*global define, console */
define('cards/message_list',['require','tmpl!./message_list.html','tmpl!./msg/header_item.html','tmpl!./msg/delete_confirm.html','mail_common','model','html_cache','message_list_topbar','l10n!'],function(require) {

var templateNode = require('tmpl!./message_list.html'),
    msgHeaderItemNode = require('tmpl!./msg/header_item.html'),
    deleteConfirmMsgNode = require('tmpl!./msg/delete_confirm.html'),
    common = require('mail_common'),
    model = require('model'),
    htmlCache = require('html_cache'),
    MessageListTopbar = require('message_list_topbar'),
    mozL10n = require('l10n!'),
    Cards = common.Cards,
    Toaster = common.Toaster,
    ConfirmDialog = common.ConfirmDialog,
    batchAddClass = common.batchAddClass,
    bindContainerClickAndHold = common.bindContainerClickAndHold,
    bindContainerHandler = common.bindContainerHandler,
    appendMatchItemTo = common.appendMatchItemTo,
    displaySubject = common.displaySubject,
    prettyDate = common.prettyDate;

/**
 * Try and keep at least this many display heights worth of undisplayed
 * messages.
 */
var SCROLL_MIN_BUFFER_SCREENS = 2;
/**
 * Keep around at most this many display heights worth of undisplayed messages.
 */
var SCROLL_MAX_RETENTION_SCREENS = 7;

/**
 * Time to wait between scroll events. Initially 150 & 325 where tried but
 * because we wait between snippet requests 50 feels about right...
 */
var SCROLL_DELAY = 50;

/**
 * Minimum number of items there must be in the message slice
 * for us to attempt to limit the selection of snippets to fetch.
 */
var MINIMUM_ITEMS_FOR_SCROLL_CALC = 10;

/**
 * Maximum amount of time between issuing snippet requests.
 */
var MAXIMUM_MS_BETWEEN_SNIPPET_REQUEST = 6000;

/**
 * Fetch up to 4kb while scrolling
 */
var MAXIMUM_BYTES_PER_MESSAGE_DURING_SCROLL = 4 * 1024;

/**
 * List messages for listing the contents of folders ('nonsearch' mode) and
 * searches ('search' mode).  Multi-editing is just a state of the card.
 *
 * Nonsearch and search modes exist together in the same card because so much
 * of what they do is the same.  We have the cards differ by marking nodes that
 * are not shared with 'msg-nonsearch-only' or 'msg-search-only'.  We add the
 * collapsed class to all of the nodes that are not applicable for a node at
 * startup.
 *
 * == Cache behavior ==
 *
 * This is a card that can be instantiated using the cached HTML stored by the
 * html_cache. As such, it is constructed to allow clicks on message list items
 * before the back end has loaded up, and to know how to refresh the cached
 * state by looking at the use the usingCachedNode property. It also prevents
 * clicks from button actions that need back end data to complete if the click
 * would result in a card that cannot also handle delayed back end startup.
 * It tracks if the back end has started up by checking curFolder, which is
 * set to a data object sent from the back end.
 *
 * == Less-than-infinite scrolling ==
 *
 * A dream UI would be to let the user smoothly scroll through all of the
 * messages in a folder, syncing them from the server as-needed.  The limits
 * on this are 1) bandwidth cost, and 2) storage limitations.
 *
 * Our sync costs are A) initial sync of a time range, and B) update sync of a
 * time range.  #A is sufficiently expensive that it makes sense to prompt the
 * user when we are going to sync further into a time range.  #B is cheap
 * enough and having already synced the time range suggests sufficient user
 * interest.
 *
 * So the way our UI works is that we do an infinite-scroll-type thing for
 * messages that we already know about.  If we are on metered bandwidth, then
 * we require the user to click a button in the display list to sync more
 * messages.  If we are on unmetered bandwidth, we will eventually forego that.
 * (For testing purposes right now, we want to pretend everything is metered.)
 * We might still want to display a button at some storage threshold level,
 * like if the folder is already using a lot of space.
 *
 * See `onScroll` for more details.
 *
 * XXX this class wants to be cleaned up, badly.  A lot of this may want to
 * happen via pushing more of the hiding/showing logic out onto CSS, taking
 * care to use efficient selectors.
 *
 */
function MessageListCard(domNode, mode, args) {
  this.domNode = domNode;
  this.mode = mode;
  this.scrollNode = domNode.getElementsByClassName('msg-list-scrollouter')[0];

  if (mode === 'nonsearch')
    batchAddClass(domNode, 'msg-search-only', 'collapsed');
  else
    batchAddClass(domNode, 'msg-nonsearch-only', 'collapsed');

  this.messagesContainer =
    domNode.getElementsByClassName('msg-messages-container')[0];

  this.messageEmptyContainer =
    domNode.getElementsByClassName('msg-list-empty-container')[0];
  // - message actions
  bindContainerClickAndHold(
    this.messagesContainer,
    // clicking shows the message reader for a message
    this.onClickMessage.bind(this),
    // press-and-hold shows the single-message mutation options
    this.onHoldMessage.bind(this));

  // - less-than-infinite scrolling
  this.scrollContainer =
    domNode.getElementsByClassName('msg-list-scrollouter')[0];
  this.scrollContainer.addEventListener('scroll', this.onScroll.bind(this),
                                        false);
  this.syncingNode =
    domNode.getElementsByClassName('msg-messages-syncing')[0];
  this.syncMoreNode =
    domNode.getElementsByClassName('msg-messages-sync-more')[0];
  this.syncMoreNode
    .addEventListener('click', this.onGetMoreMessages.bind(this), false);

  // - header buttons: non-edit mode
  domNode.getElementsByClassName('msg-folder-list-btn')[0]
    .addEventListener('click', this.onShowFolders.bind(this), false);
  domNode.getElementsByClassName('msg-compose-btn')[0]
    .addEventListener('click', this.onCompose.bind(this), false);

  // - toolbar: non-edit mode
  this.toolbar = {};
  this.toolbar.searchBtn = domNode.getElementsByClassName('msg-search-btn')[0];
  this.toolbar.searchBtn
    .addEventListener('click', this.onSearchButton.bind(this), false);
  this.toolbar.editBtn = domNode.getElementsByClassName('msg-edit-btn')[0];
  this.toolbar.editBtn
    .addEventListener('click', this.setEditMode.bind(this, true), false);
  this.toolbar.refreshBtn =
    domNode.getElementsByClassName('msg-refresh-btn')[0];
  this.toolbar.refreshBtn
    .addEventListener('click', this.onRefresh.bind(this), false);

  // - header buttons: edit mode
  domNode.getElementsByClassName('msg-listedit-cancel-btn')[0]
    .addEventListener('click', this.setEditMode.bind(this, false), false);

  // - toolbar: edit mode
  domNode.getElementsByClassName('msg-star-btn')[0]
    .addEventListener('click', this.onStarMessages.bind(this, true), false);
  domNode.getElementsByClassName('msg-mark-read-btn')[0]
    .addEventListener('click', this.onMarkMessagesRead.bind(this, true), false);
  domNode.getElementsByClassName('msg-delete-btn')[0]
    .addEventListener('click', this.onDeleteMessages.bind(this, true), false);
  this.toolbar.moveBtn = domNode.getElementsByClassName('msg-move-btn')[0];
  this.toolbar.moveBtn
    .addEventListener('click', this.onMoveMessages.bind(this, true), false);

  // -- non-search mode
  if (mode === 'nonsearch') {
    // - search teaser bar
    // Focusing the teaser bar's text field is the same as hitting the search
    // button.
    domNode.getElementsByClassName('msg-search-text-tease')[0]
      .addEventListener('focus', this.onSearchButton.bind(this), false);
  }
  // -- search mode
  else if (mode === 'search') {
    domNode.getElementsByClassName('msg-search-cancel')[0]
      .addEventListener('click', this.onCancelSearch.bind(this), false);

    bindContainerHandler(
      domNode.getElementsByClassName('filter')[0],
      'click', this.onSearchFilterClick.bind(this));
    this.searchInput = domNode.getElementsByClassName('msg-search-text')[0];
    this.searchInput.addEventListener(
      'input', this.onSearchTextChange.bind(this), false);
  }

  // convenience wrapper for context.
  this._onScroll = this._onScroll.bind(this);

  this.editMode = false;
  this.selectedMessages = null;

  this.curFolder = null;
  this.messagesSlice = null;
  this.isIncomingFolder = true;
  this._boundSliceRequestComplete = this.onSliceRequestComplete.bind(this);

  this.usingCachedNode = !!args.cachedNode;

  this._boundFolderChanged = this._folderChanged.bind(this);
  model.latest('folder', this._boundFolderChanged);

  this._boundOnNewMail = this.onNewMail.bind(this);
  model.on('newInboxMessages', this._boundOnNewMail);
}
MessageListCard.prototype = {
  /**
   * How many milliseconds since our last progress update event before we put
   * the progressbar in the indeterminate "candybar" state?
   *
   * This value is currently arbitrarily chosen by asuth to try and avoid us
   * flipping back and forth from non-candybar state to candybar state
   * frequently.  This should be updated with UX or VD feedback.
   */
  PROGRESS_CANDYBAR_TIMEOUT_MS: 2000,

  /**
   * @type {MessageListTopbar}
   * @private
   */
  _topbar: null,

  postInsert: function() {
    this._hideSearchBoxByScrolling();

    if (this.mode === 'search')
      this.searchInput.focus();
  },

  onSearchButton: function() {
    // Do not bother if there is no current folder.
    if (!this.curFolder)
      return;

    Cards.pushCard(
      'message_list', 'search', 'animate',
      {
        folder: this.curFolder
      });
  },

  setEditMode: function(editMode) {
    // Do not bother if this is triggered before
    // a folder has loaded.
    if (!this.curFolder)
      return;

    var domNode = this.domNode;
    // XXX the manual DOM play here is now a bit overkill; we should very
    // probably switch top having the CSS do this for us or at least invest
    // some time in cleanup.
    var normalHeader = domNode.getElementsByClassName('msg-list-header')[0],
        searchHeader = domNode.getElementsByClassName('msg-search-header')[0],
        editHeader = domNode.getElementsByClassName('msg-listedit-header')[0],
        normalToolbar =
          domNode.getElementsByClassName('msg-list-action-toolbar')[0],
        editToolbar =
          domNode.getElementsByClassName('msg-listedit-action-toolbar')[0];

    this.editMode = editMode;

    if (editMode) {
      normalHeader.classList.add('collapsed');
      searchHeader.classList.add('collapsed');
      normalToolbar.classList.add('collapsed');
      editHeader.classList.remove('collapsed');
      editToolbar.classList.remove('collapsed');
      this.messagesContainer.classList.add('show-edit');

      this.selectedMessages = [];
      var cbs = this.messagesContainer.querySelectorAll('input[type=checkbox]');
      for (var i = 0; i < cbs.length; i++) {
        cbs[i].checked = false;
      }
      this.selectedMessagesUpdated();
    }
    else {
      if (this.mode === 'nonsearch')
        normalHeader.classList.remove('collapsed');
      else
        searchHeader.classList.remove('collapsed');
      normalToolbar.classList.remove('collapsed');
      editHeader.classList.add('collapsed');
      editToolbar.classList.add('collapsed');
      this.messagesContainer.classList.remove('show-edit');

      // (Do this based on the DOM nodes actually present; if the user has been
      // scrolling a lot, this.selectedMessages may contain messages that no
      // longer have a domNode around.)
      var selectedMsgNodes =
        domNode.getElementsByClassName('msg-header-item-selected');
      for (var i = selectedMsgNodes.length - 1; i >= 0; i--) {
        selectedMsgNodes[i].classList.remove('msg-header-item-selected');
      }

      this.selectedMessages = null;
    }

    // UXXX do we want to disable the buttons if nothing is selected?
  },

  /**
   * Update the edit mode UI bits sensitive to a change in the set of selected
   * messages.  This means: the label that says how many messages are selected,
   * whether the buttons are enabled, which of the toggle-pairs are visible.
   */
  selectedMessagesUpdated: function() {
    var headerNode =
      this.domNode.getElementsByClassName('msg-listedit-header-label')[0];
    headerNode.textContent =
      mozL10n.get('message-multiedit-header',
                  { n: this.selectedMessages.length });

    var starBtn = this.domNode.getElementsByClassName('msg-star-btn')[0],
        readBtn = this.domNode.getElementsByClassName('msg-mark-read-btn')[0];

    // Enabling/disabling rules (not UX-signed-off):  Our bias is that people
    // want to star messages and mark messages unread (since it they naturally
    // end up unread), so unless messages are all in this state, we assume that
    // is the desired action.
    var numStarred = 0, numRead = 0;
    for (var i = 0; i < this.selectedMessages.length; i++) {
      var msg = this.selectedMessages[i];
      if (msg.isStarred)
        numStarred++;
      if (msg.isRead)
        numRead++;
    }

    // Unstar if everything is starred, otherwise star
    this.setAsStarred = !(numStarred && numStarred ===
                          this.selectedMessages.length);
    // Mark read if everything is unread, otherwise unread
    this.setAsRead = (this.selectedMessages.length && numRead === 0);

    if (!this.setAsStarred)
      starBtn.classList.add('msg-btn-active');
    else
      starBtn.classList.remove('msg-btn-active');

    if (this.setAsRead)
      readBtn.classList.add('msg-btn-active');
    else
      readBtn.classList.remove('msg-btn-active');
  },

  _hideSearchBoxByScrolling: function() {
    // scroll the search bit out of the way
    var searchBar =
      this.domNode.getElementsByClassName('msg-search-tease-bar')[0];

    // Search bar could have been collapsed with a cache load, make sure
    // it is visible
    searchBar.classList.remove('collapsed');

    this.scrollNode.scrollTop = searchBar.offsetHeight;
  },

  onShowFolders: function() {
    var query = ['folder_picker', 'navigation'];
    if (Cards.hasCard(query)) {
      Cards.moveToCard(query);
    } else {
      // Add navigation, but before the message list.
      Cards.pushCard(
        'folder_picker', 'navigation', 'none',
        {
          onPushed: function() {
            setTimeout(function() {
            // Do showCard here instead of using an 'animate'
            // for the pushCard call, since the styling of
            // the folder_picker uses new images that need to
            // load, and if 'animate' is used, the banner
            // gradient is not loaded during the transition.
            // The setTimeout also gives the header image a
            // chance to finish loading. Without it, there is
            // still a white flash. Going lower than 50, not
            // specifying a value, still resulted in white flash.
            Cards.moveToCard(query);
          }, 50);
          }.bind(this)
        },
        // Place to left of message list
        'left');
    }
  },

  onCompose: function() {
    Cards.pushCard('compose', 'default', 'animate');
  },

  /**
   * Show a folder, returning true if we actually changed folders or false if
   * we did nothing because we were already in the folder.
   */
  showFolder: function(folder, forceNewSlice) {
    if (folder === this.curFolder && !forceNewSlice)
      return false;

    if (this.messagesSlice) {
      this.messagesSlice.die();
      this.messagesSlice = null;
      this.messagesContainer.innerHTML = '';
    }

    this.curFolder = folder;

    switch (folder.type) {
      case 'drafts':
      case 'localdrafts':
      case 'sent':
        this.isIncomingFolder = false;
        break;
      default:
        this.isIncomingFolder = true;
        break;
    }

    this.domNode.getElementsByClassName('msg-list-header-folder-label')[0]
      .textContent = folder.name;

    this.hideEmptyLayout();

    // you can't refresh the localdrafts folder or move messages out of it.
    if (folder.type === 'localdrafts') {
      this.toolbar.refreshBtn.classList.add('collapsed');
      this.toolbar.moveBtn.classList.add('collapsed');
    }
    else {
      this.toolbar.refreshBtn.classList.remove('collapsed');
      this.toolbar.moveBtn.classList.remove('collapsed');
    }

    // We are creating a new slice, so any pending snippet requests are moot.
    this._snippetRequestPending = false;
    this.messagesSlice = model.api.viewFolderMessages(folder);

    this.messagesSlice.onsplice = this.onMessagesSplice.bind(this);
    this.messagesSlice.onchange = this.onMessagesChange.bind(this);
    this.messagesSlice.onstatus = this.onStatusChange.bind(this);
    this.messagesSlice.oncomplete = this._boundSliceRequestComplete;
    return true;
  },

  showSearch: function(folder, phrase, filter) {
    console.log('sf: showSearch. phrase:', phrase, phrase.length);
    var tab = this.domNode.getElementsByClassName('filter')[0];
    var nodes = tab.getElementsByClassName('msg-search-filter');
    if (this.messagesSlice) {
      this.messagesSlice.die();
      this.messagesSlice = null;
      this.messagesContainer.innerHTML = '';
    }
    this.curFolder = folder;
    this.curPhrase = phrase;
    this.curFilter = filter;

    for (var i = 0; i < nodes.length; i++) {
      if (nodes[i].dataset.filter != this.curFilter) {
        nodes[i].setAttribute('aria-selected', 'false');
        continue;
      }
      nodes[i].setAttribute('aria-selected', 'true');
    }
    if (phrase.length < 1)
      return false;

    // We are creating a new slice, so any pending snippet requests are moot.
    this._snippetRequestPending = false;
    this.messagesSlice = model.api.searchFolderMessages(
      folder, phrase,
      {
        author: filter === 'all' || filter === 'author',
        recipients: filter === 'all' || filter === 'recipients',
        subject: filter === 'all' || filter === 'subject',
        body: filter === 'all' || filter === 'body'
      });
    this.messagesSlice.onsplice = this.onMessagesSplice.bind(this);
    this.messagesSlice.onchange = this.updateMatchedMessageDom.bind(this,
                                                                    false);
    this.messagesSlice.onstatus = this.onStatusChange.bind(this);
    this.messagesSlice.oncomplete = this._boundSliceRequestComplete;
    return true;
  },

  onSearchFilterClick: function(filterNode, event) {
    this.showSearch(this.curFolder, this.searchInput.value,
                    filterNode.dataset.filter);
  },

  onSearchTextChange: function(event) {
    console.log('sf: typed, now:', this.searchInput.value);
    this.showSearch(this.curFolder, this.searchInput.value, this.curFilter);
  },

  onCancelSearch: function(event) {
    try {
      if (this.messagesSlice)
        this.messagesSlice.die();
    }
    catch (ex) {
      console.error('problem killing slice:', ex, '\n', ex.stack);
    }
    this.messagesSlice = null;
    Cards.removeCardAndSuccessors(this.domNode, 'animate');
  },

  onGetMoreMessages: function() {
    if (!this.messagesSlice)
      return;

    this.messagesSlice.requestGrowth(1, true);
    // Provide instant feedback that they pressed the button by hiding the
    // button.  However, don't show 'synchronizing' because that might not
    // actually happen.
    this.syncMoreNode.classList.add('collapsed');
  },

  onStatusChange: function(newStatus) {
    switch (newStatus) {
      case 'synchronizing':
      case 'syncblocked':
        this.syncingNode.classList.remove('collapsed');
        this.syncMoreNode.classList.add('collapsed');
        this.hideEmptyLayout();

        this.toolbar.refreshBtn.dataset.state = 'synchronizing';
        break;
      case 'syncfailed':
        // If there was a problem talking to the server, notify the user and
        // provide a means to attempt to talk to the server again.  We have made
        // onRefresh pretty clever, so it can do all the legwork on
        // accomplishing this goal.
        Toaster.logRetryable(newStatus, this.onRefresh.bind(this));

        // Fall through...
      case 'synced':
        this.toolbar.refreshBtn.dataset.state = 'synchronized';
        this.syncingNode.classList.add('collapsed');
        break;
    }
  },

  /**
   * Hide buttons that are not appropriate if we have no messages and display
   * the appropriate l10n string in the message list proper.
   */
  showEmptyLayout: function() {
    var text = this.domNode.
      getElementsByClassName('msg-list-empty-message-text')[0];

    this._clearCachedMessages();

    text.textContent = this.mode == 'search' ?
      mozL10n.get('messages-search-empty') :
      mozL10n.get('messages-folder-empty');
    this.messageEmptyContainer.classList.remove('collapsed');
    this.toolbar.editBtn.classList.add('disabled');
    this.toolbar.searchBtn.classList.add('disabled');
    this._hideSearchBoxByScrolling();
  },
  /**
   * Show buttons we hid in `showEmptyLayout` and hide the "empty folder"
   * message.
   */
  hideEmptyLayout: function() {
    this.messageEmptyContainer.classList.add('collapsed');
    this.toolbar.editBtn.classList.remove('disabled');
    this.toolbar.searchBtn.classList.remove('disabled');
  },


  /**
   * @param {number=} newEmailCount Optional number of new messages.
   */
  onSliceRequestComplete: function(newEmailCount) {
    // We always want our logic to fire, but complete auto-clears before firing.
    this.messagesSlice.oncomplete = this._boundSliceRequestComplete;

    if (this.messagesSlice.userCanGrowDownwards)
      this.syncMoreNode.classList.remove('collapsed');
    else
      this.syncMoreNode.classList.add('collapsed');

    // Show empty layout, unless this is a slice with fake data that
    // will get changed soon.
    if (this.messagesSlice.items.length === 0) {
      this.showEmptyLayout();
    }

    this.onNewMail(newEmailCount);

    // Consider requesting more data or discarding data based on scrolling that
    // has happened since we issued the request.  (While requests were pending,
    // onScroll ignored scroll events.)
    this._onScroll(null);
  },

  onNewMail: function(newEmailCount) {
    var inboxFolder = model.foldersSlice.getFirstFolderWithType('inbox');

    if (inboxFolder.id === this.curFolder.id &&
        newEmailCount && newEmailCount !== NaN && newEmailCount !== 0) {
      if (!Cards.isVisible(this)) {
        this._whenVisible = this.onNewMail.bind(this, newEmailCount);
        return;
      }

      // Decorate or update the little notification bar that tells the user
      // how many new emails they've received after a sync.
      if (this._topbar && this._topbar.getElement() !== null) {
        // Update the existing status bar.
        this._topbar.updateNewEmailCount(newEmailCount);
      } else {
        this._topbar = new MessageListTopbar(
            this.scrollContainer, newEmailCount);

        var el =
            document.getElementsByClassName(MessageListTopbar.CLASS_NAME)[0];
        this._topbar.decorate(el);
        this._topbar.render();
      }
    }
  },

  onScroll: function(evt) {
    if (this._pendingScrollEvent) {
      return;
    }

    this._pendingScrollEvent = true;
    this._scrollTimer = setTimeout(this._onScroll, SCROLL_DELAY, evt);
  },

  /**
   * Handle scrolling by requesting more messages when we have less than the
   * minimum buffer space and trimming messages when we have more than the max.
   *
   * We don't care about the direction of scrolling, which is helpful since this
   * also lets us handle cases where message deletion might have done bad things
   * to us.  (It does, however, open the door to foolishness where we request
   * data and then immediately discard some of it.)
   */
  _onScroll: function(event) {
    if (this._pendingScrollEvent) {
      this._pendingScrollEvent = false;
    }


    // Defer processing until any pending requests have completed;
    // `onSliceRequestComplete` will call us.
    if (!this.messagesSlice || this.messagesSlice.pendingRequestCount)
      return;

    if (!this._hasSnippetRequest()) {
      this._requestSnippets();
    }

    var curScrollTop = this.scrollContainer.scrollTop,
        viewHeight = this.scrollContainer.clientHeight;

    var preScreens = curScrollTop / viewHeight,
        postScreens = (this.scrollContainer.scrollHeight -
                       (curScrollTop + viewHeight)) /
                      viewHeight;

    var shrinkLowIncl = 0,
        shrinkHighIncl = this.messagesSlice.items.length - 1,
        messageNode = null, targOff;
    if (preScreens < SCROLL_MIN_BUFFER_SCREENS &&
        !this.messagesSlice.atTop) {
      this.messagesSlice.requestGrowth(-1);
      return;
    }
    else if (preScreens > SCROLL_MAX_RETENTION_SCREENS) {
      // Take off one screen at a time.
      targOff = curScrollTop -
                (viewHeight * (SCROLL_MAX_RETENTION_SCREENS - 1));
      for (messageNode = this.messagesContainer.firstElementChild;
           messageNode.offsetTop + messageNode.clientHeight < targOff;
           messageNode = messageNode.nextElementSibling) {
        shrinkLowIncl++;
      }
    }

    if (postScreens < SCROLL_MIN_BUFFER_SCREENS &&
        !this.messagesSlice.atBottom) {
      this.messagesSlice.requestGrowth(1);
    }
    else if (postScreens > SCROLL_MAX_RETENTION_SCREENS) {
      targOff = curScrollTop +
                this.scrollContainer.clientHeight +
                (viewHeight * (SCROLL_MAX_RETENTION_SCREENS - 1));
      for (messageNode = this.messagesContainer.lastElementChild;
           messageNode.offsetTop > targOff;
           messageNode = messageNode.previousElementSibling) {
        shrinkHighIncl--;
      }
    }

    if (shrinkLowIncl !== 0 ||
        shrinkHighIncl !== this.messagesSlice.items.length - 1) {
      this.messagesSlice.requestShrinkage(shrinkLowIncl, shrinkHighIncl);
    }

  },

  _hasSnippetRequest: function() {
    var max = MAXIMUM_MS_BETWEEN_SNIPPET_REQUEST;
    var now = Date.now();

    // if we before the maximum time to wait between requests...
    var beforeTimeout =
      (this._lastSnippetRequest + max) > now;

    // there is an important case where the backend may be slow OR have some
    // fatal error which would prevent us from ever requesting an new set of
    // snippets because we wait until the last batch finishes... To prevent that
    // from ever happening we maintain the request start time and if more then
    // MAXIMUM_MS_BETWEEN_SNIPPET_REQUEST passes we issue a new request.
    if (
      this._snippetRequestPending &&
      beforeTimeout
    ) {
      return true;
    }

    return false;
  },

  _pendingSnippetRequest: function() {
    this._snippetRequestPending = true;
    this._lastSnippetRequest = Date.now();
  },

  _clearSnippetRequest: function() {
    this._snippetRequestPending = false;
  },

  _requestSnippets: function() {
    var items = this.messagesSlice.items;
    var len = items.length;

    if (!len)
      return;

    var clearSnippets = this._clearSnippetRequest.bind(this);
    var options = {
      // this is per message
      maximumBytesToFetch: MAXIMUM_BYTES_PER_MESSAGE_DURING_SCROLL
    };

    if (len < MINIMUM_ITEMS_FOR_SCROLL_CALC) {
      this._pendingSnippetRequest();
      this.messagesSlice.maybeRequestBodies(0, 9, options, clearSnippets);
      return;
    }

    // get the scrollable offset
    if (!this._scrollContainerOffset) {
      this._scrollContainerRect =
        this.scrollContainer.getBoundingClientRect();
    }

    var constOffset = this._scrollContainerRect.top;

    // determine where we are in the list;
    var topOffset = (
      items[0].element.getBoundingClientRect().top - constOffset
    );

    // the distance between items. It is expected to remain fairly constant
    // throughout the list so we only need to calculate it once.

    var distance = this._distanceBetweenMessages;
    if (!distance) {
      this._distanceBetweenMessages = distance = Math.abs(
        topOffset -
        (items[1].element.getBoundingClientRect().top - constOffset)
      );
    }

    // starting offset to begin fetching snippets
    var startOffset = Math.floor(Math.abs(topOffset / distance));

    this._snippetsPerScrollTick = (
      this._snippetsPerScrollTick ||
      Math.ceil(this._scrollContainerRect.height / distance)
    );


    this._pendingSnippetRequest();
    this.messagesSlice.maybeRequestBodies(
      startOffset,
      startOffset + this._snippetsPerScrollTick,
      options,
      clearSnippets
    );

  },

  /**
   * How many items in the message list to keep for the _cacheDom call.
   * @type {Number}
   */
  _cacheListLimit: 7,

  /**
   * Tracks if a DOM cache save is scheduled for later.
   * @type {Number}
   */
  _cacheDomTimeoutId: 0,

  /**
   * Caches the DOM for this card, but trims it down a bit first.
   */
  _cacheDom: function() {
    this._cacheDomTimeoutId = 0;

    var cacheNode = this.domNode.cloneNode(true);


    // Hide search field as it will not operate and gets scrolled out
    // of view after real load.
    var removableCacheNode = cacheNode.querySelector('.msg-search-tease-bar');
    if (removableCacheNode)
      removableCacheNode.classList.add('collapsed');

    // Hide "new mail" topbar too
    removableCacheNode = cacheNode
                           .querySelector('.' + MessageListTopbar.CLASS_NAME);
    if (removableCacheNode)
      removableCacheNode.classList.add('collapsed');

    // Trim the message list to _cacheListLimit.
    if (this.messagesContainer.children.length > this._cacheListLimit) {
      var msgContainer = cacheNode
                        .getElementsByClassName('msg-messages-container')[0];
      for (var childIndex = msgContainer.children.length - 1;
                            childIndex > this._cacheListLimit - 1;
                            childIndex--) {
        var childNode = msgContainer.children[childIndex];
        childNode.parentNode.removeChild(childNode);
      }
    }
    htmlCache.saveFromNode(cacheNode);
  },

  /**
   * Considers a DOM cache, but only if it meets the criteria for what
   * should be saved in the cache, and if a save is not already scheduled.
   * @param  {Number} index the index of the message that triggered
   *                  this call.
   */
  _considerCacheDom: function(index) {
    // Only bother if not already waiting to update cache and
    if (!this._cacheDomTimeoutId &&
        // is for the folder that is considered cacheable (default inbox)
        this.cacheableFolderId === this.curFolder.id &&
        // if our slice is showing the newest messages in the folder and
        this.messagesSlice.atTop &&
        // if actually got a numeric index and
        (index || index === 0) &&
        // if it affects the data we cache
        index < this._cacheListLimit &&
        // is in non-search mode
        this.mode === 'nonsearch') {
      this._cacheDomTimeoutId = setTimeout(this._cacheDom.bind(this), 600);
    }
  },

  /**
   * Clears out the messages HTML in messageContainer from using the cached
   * nodes that were picked up when the HTML cache of this list was used
   * (which is indicated by usingCachedNode being true). The cached HTML
   * needs to be purged when the real data is finally available and will
   * replace the cached state. A more sophisticated approach would be to
   * compare the cached HTML to what would be inserted in its place, and
   * if no changes, skip this step, but that comparison operation could get
   * tricky, and it is cleaner just to wipe it and start fresh. Once the
   * cached HTML has been cleared, then usingCachedNode is set to false
   * to indicate that the main piece of content in the card, the message
   * list, is no longer from a cached node.
   */
  _clearCachedMessages: function() {
    if (this.usingCachedNode) {
      this.messagesContainer.innerHTML = '';
      this.usingCachedNode = false;
    }
  },

  onMessagesSplice: function(index, howMany, addedItems,
                             requested, moreExpected, fake) {
    // If no work to do, just skip it.
    if (index === 0 && howMany === 0 && !addedItems.length)
      return;

    var prevHeight;
    // - removed messages
    if (howMany) {
      if (fake && index === 0 && this.messagesSlice.items.length === howMany &&
          !addedItems.length) {
      } else {
        // Regular remove for current call.
        // Plan to fixup the scroll position if we are deleting a message that
        // starts before the (visible) scrolled area.  (We add the container's
        // start offset because it is as big as the occluding header bar.)
        prevHeight = null;
        if (this.messagesSlice.items[index].element.offsetTop <
            this.scrollContainer.scrollTop + this.messagesContainer.offsetTop) {
          prevHeight = this.messagesContainer.clientHeight;
        }

        for (var i = index + howMany - 1; i >= index; i--) {
          var message = this.messagesSlice.items[i];
          message.element.parentNode.removeChild(message.element);
        }

        // If fixup is requred, adjust.
        if (prevHeight !== null) {
          this.scrollContainer.scrollTop -=
            (prevHeight - this.messagesContainer.clientHeight);
        }

        // Check the message count after deletion:
        if (this.messagesContainer.children.length === 0) {
          this.showEmptyLayout();
        }
      }
    }

    this._clearCachedMessages();

    // - added/existing
    var insertBuddy, self = this;
    if (index >= this.messagesContainer.childElementCount)
      insertBuddy = null;
    else
      insertBuddy = this.messagesContainer.children[index];
    if (insertBuddy &&
        (insertBuddy.offsetTop <
         this.scrollContainer.scrollTop + this.messagesContainer.offsetTop))
      prevHeight = this.messagesContainer.clientHeight;
    else
      prevHeight = null;

    // Remove the no message text while new messages added:
    if (addedItems.length > 0) {
      this.hideEmptyLayout();
    }

    addedItems.forEach(function(message, i) {
      var domMessage;
      domMessage = message.element = msgHeaderItemNode.cloneNode(true);

      if (self.mode === 'nonsearch') {
        domMessage.message = message;
        self.updateMessageDom(true, message);
      }
      else {
        domMessage.message = message.header;
        self.updateMatchedMessageDom(true, message);
      }

      self.messagesContainer.insertBefore(domMessage, insertBuddy);
    });

    if (prevHeight) {
      this.scrollContainer.scrollTop +=
        (this.messagesContainer.clientHeight - prevHeight);
    }

    // Only cache if it is an add or remove of items
    if (addedItems.length || howMany) {
      this._considerCacheDom(index);
    }
  },

  onMessagesChange: function(message, index) {
    this.updateMessageDom(false, message);

    // Since the DOM change, cache may need to change.
    this._considerCacheDom(index);
  },

  _updatePeepDom: function(peep) {
    peep.element.textContent = peep.name || peep.address;
  },

  updateMessageDom: function(firstTime, message) {
    var msgNode = message.element;

    // ID is stored as a data- attribute so that it can survive
    // serialization to HTML for storing in the HTML cache, and
    // be usable before the actual data from the backend has
    // loaded, as clicks to the message list are allowed before
    // the back end is available. For this reason, click
    // handlers should use dataset.id when wanting the ID.
    msgNode.dataset.id = message.id;

    // some things only need to be done once
    var dateNode = msgNode.getElementsByClassName('msg-header-date')[0];
    if (firstTime) {
      var listPerson;
      if (this.isIncomingFolder)
        listPerson = message.author;
      // XXX This is not to UX spec, but this is a stop-gap and that would
      // require adding strings which we cannot justify as a slipstream fix.
      else if (message.to && message.to.length)
        listPerson = message.to[0];
      else if (message.cc && message.cc.length)
        listPerson = message.cc[0];
      else if (message.bcc && message.bcc.length)
        listPerson = message.bcc[0];
      else
        listPerson = message.author;

      // author
      listPerson.element =
        msgNode.getElementsByClassName('msg-header-author')[0];
      listPerson.onchange = this._updatePeepDom;
      listPerson.onchange(listPerson);
      // date
      dateNode.dataset.time = message.date.valueOf();
      dateNode.textContent = prettyDate(message.date);
      // subject
      displaySubject(msgNode.getElementsByClassName('msg-header-subject')[0],
                     message);
      // attachments
      if (message.hasAttachments)
        msgNode.getElementsByClassName('msg-header-attachments')[0]
          .classList.add('msg-header-attachments-yes');
    }

    // snippet
    msgNode.getElementsByClassName('msg-header-snippet')[0]
      .textContent = message.snippet;

    // unread (we use very specific classes directly on the nodes rather than
    // child selectors for hypothetical speed)
    var unreadNode =
      msgNode.getElementsByClassName('msg-header-unread-section')[0];
    if (message.isRead) {
      unreadNode.classList.remove('msg-header-unread-section-unread');
      dateNode.classList.remove('msg-header-date-unread');
    }
    else {
      unreadNode.classList.add('msg-header-unread-section-unread');
      dateNode.classList.add('msg-header-date-unread');
    }
    // star
    var starNode = msgNode.getElementsByClassName('msg-header-star')[0];
    if (message.isStarred)
      starNode.classList.add('msg-header-star-starred');
    else
      starNode.classList.remove('msg-header-star-starred');
  },

  updateMatchedMessageDom: function(firstTime, matchedHeader) {
    var msgNode = matchedHeader.element,
        matches = matchedHeader.matches,
        message = matchedHeader.header;

    // Even though updateMatchedMessageDom is only used in searches,
    // which likely will not be cached, the dataset.is is set to
    // maintain parity withe updateMessageDom and so click handlers
    // can always just use the dataset property.
    msgNode.dataset.id = matchedHeader.id;

    // some things only need to be done once
    var dateNode = msgNode.getElementsByClassName('msg-header-date')[0];
    if (firstTime) {
      // author
      var authorNode = msgNode.getElementsByClassName('msg-header-author')[0];
      if (matches.author) {
        appendMatchItemTo(matches.author, authorNode);
      }
      else {
        // we can only update the name if it wasn't matched on.
        message.author.element = authorNode;
        message.author.onchange = this._updatePeepDom;
        message.author.onchange(message.author);
      }

      // date
      dateNode.dataset.time = message.date.valueOf();
      dateNode.textContent = prettyDate(message.date);

      // subject
      var subjectNode = msgNode.getElementsByClassName('msg-header-subject')[0];
      if (matches.subject)
        appendMatchItemTo(matches.subject[0], subjectNode);
      else
        displaySubject(subjectNode, message);

      // snippet
      var snippetNode = msgNode.getElementsByClassName('msg-header-snippet')[0];
      if (matches.body)
       appendMatchItemTo(matches.body[0], snippetNode);
      else
        snippetNode.textContent = message.snippet;

      // attachments
      if (message.hasAttachments)
        msgNode.getElementsByClassName('msg-header-attachments')[0]
          .classList.add('msg-header-attachments-yes');
    }

    // unread (we use very specific classes directly on the nodes rather than
    // child selectors for hypothetical speed)
    var unreadNode =
      msgNode.getElementsByClassName('msg-header-unread-section')[0];
    if (message.isRead) {
      unreadNode.classList.remove('msg-header-unread-section-unread');
      dateNode.classList.remove('msg-header-date-unread');
    }
    else {
      unreadNode.classList.add('msg-header-unread-section-unread');
      dateNode.classList.add('msg-header-date-unread');
    }
    // star
    var starNode = msgNode.getElementsByClassName('msg-header-star')[0];
    if (message.isStarred)
      starNode.classList.add('msg-header-star-starred');
    else
      starNode.classList.remove('msg-header-star-starred');
  },

  /**
   * Called by Cards when the instance of this card type is the
   * visible card.
   */
  onCardVisible: function() {
    if (this._whenVisible) {
      var fn = this._whenVisible;
      this._whenVisible = null;
      fn();
    }
  },

  onClickMessage: function(messageNode, event) {
    var header = messageNode.message;
    if (this.editMode) {
      var idx = this.selectedMessages.indexOf(header);
      var cb = messageNode.querySelector('input[type=checkbox]');
      if (idx !== -1) {
        this.selectedMessages.splice(idx, 1);
        cb.checked = false;
      }
      else {
        this.selectedMessages.push(header);
        cb.checked = true;
      }
      this.selectedMessagesUpdated();
      return;
    }

    if (this.curFolder && this.curFolder.type === 'localdrafts') {
      var composer = header.editAsDraft(function() {
        Cards.pushCard('compose', 'default', 'animate',
                       { composer: composer });
      });
      return;
    }

    Cards.pushCard(
      'message_reader', 'default', 'animate',
      {
        // The header here may be undefined here, since the click
        // could be on a cached HTML node before the back end has
        // started up. It is OK if header is not available as the
        // message_reader knows how to wait for the back end to
        // start up to get the header value later.
        header: header,
        // Use the property on the HTML, since the click could be
        // from a cached HTML node and the real data object may not
        // be available yet.
        messageSuid: messageNode.dataset.id
      });
  },

  onHoldMessage: function(messageNode, event) {
    if (this.curFolder)
      this.setEditMode(true);
  },

  onRefresh: function() {
    if (!this.messagesSlice)
      return;

    switch (this.messagesSlice.status) {
      // If we're still synchronizing, then the user is not well served by
      // queueing a refresh yet, let's just squash this.
      case 'new':
      case 'synchronizing':
        break;
      // If we fully synchronized, then yes, let us refresh.
      case 'synced':
        this.messagesSlice.refresh();
        break;
      // If we failed to talk to the server, then let's only do a refresh if we
      // know about any messages.  Otherwise let's just create a new slice by
      // forcing reentry into the folder.
      case 'syncfailed':
        if (this.messagesSlice.items.length)
          this.messagesSlice.refresh();
        else
          this.showFolder(this.curFolder, /* force new slice */ true);
        break;
    }
  },

  onStarMessages: function() {
    var op = model.api.markMessagesStarred(this.selectedMessages,
                                         this.setAsStarred);
    this.setEditMode(false);
    Toaster.logMutation(op);
  },

  onMarkMessagesRead: function() {
    var op = model.api.markMessagesRead(this.selectedMessages, this.setAsRead);
    this.setEditMode(false);
    Toaster.logMutation(op);
  },

  onDeleteMessages: function() {
    // TODO: Batch delete back-end mail api is not ready for IMAP now.
    //       Please verify this function under IMAP when api completed.

    if (this.selectedMessages.length === 0)
      return;

    var dialog = deleteConfirmMsgNode.cloneNode(true);
    var content = dialog.getElementsByTagName('p')[0];
    content.textContent = mozL10n.get('message-multiedit-delete-confirm',
                                      { n: this.selectedMessages.length });
    ConfirmDialog.show(dialog,
      { // Confirm
        id: 'msg-delete-ok',
        handler: function() {
          var op = model.api.deleteMessages(this.selectedMessages);
          Toaster.logMutation(op);
          this.setEditMode(false);
        }.bind(this)
      },
      { // Cancel
        id: 'msg-delete-cancel',
        handler: null
      }
    );
  },

  onMoveMessages: function() {
    // TODO: Batch move back-end mail api is not ready now.
    //       Please verify this function when api landed.
    Cards.folderSelector(function(folder) {
      var op = model.api.moveMessages(this.selectedMessages, folder);
      Toaster.logMutation(op);
      this.setEditMode(false);
    }.bind(this));
  },

  _folderChanged: function(folder) {
    // Folder could have changed because account changed. Make sure
    // the cacheableFolderId is still set correctly.
    var inboxFolder = model.foldersSlice.getFirstFolderWithType('inbox');
    this.cacheableFolderId = model.account === model.acctsSlice.defaultAccount ?
                                               inboxFolder.id : null;

    this.folder = folder;

    if (this.mode == 'nonsearch') {
      if (this.showFolder(folder)) {
        this._hideSearchBoxByScrolling();
      }
    } else {
      this.showSearch(folder, '', 'all');
    }
  },

  die: function() {
    if (this.messagesSlice) {
      this.messagesSlice.die();
      this.messagesSlice = null;
    }
    model.removeListener('folder', this._boundFolderChanged);
    model.removeListener('newInboxMessages', this._boundOnNewMail);
  }
};
Cards.defineCard({
  name: 'message_list',
  modes: {
    nonsearch: {
      tray: false
    },
    search: {
      tray: false
    }
  },
  constructor: MessageListCard,
  templateNode: templateNode
});

return MessageListCard;
});

/**
 * Application logic that isn't specific to cards, specifically entailing
 * startup and eventually notifications.
 **/
/*jshint browser: true */
/*global define, requirejs, confirm, console, TestUrlResolver */

// Set up loading of scripts, but only if not in tests, which set up
// their own config.
if (typeof TestUrlResolver === 'undefined') {
  requirejs.config({
    baseUrl: 'js',
    paths: {
      l10nbase: '../shared/js/l10n',
      l10ndate: '../shared/js/l10n_date',
      style: '../style',
      shared: '../shared',

      'mailapi/main-frame-setup': 'ext/mailapi/main-frame-setup',
      'mailapi/main-frame-backend': 'ext/mailapi/main-frame-backend'
    },
    map: {
      '*': {
        'api': 'mailapi/main-frame-setup'
      }
    },
    shim: {
      l10ndate: ['l10nbase'],

      'shared/js/mime_mapper': {
        exports: 'MimeMapper'
      },

      'shared/js/notification_helper': {
        exports: 'NotificationHelper'
      }
    },
    definePrim: 'prim'
  });
}

// Named module, so it is the same before and after build, and referenced
// in the require at the end of this file.
define('mail_app', ['require','exports','module','app_messages','html_cache','l10n!','mail_common','evt','model','sync','wake_locks'],function(require, exports, module) {

var appMessages = require('app_messages'),
    htmlCache = require('html_cache'),
    mozL10n = require('l10n!'),
    common = require('mail_common'),
    evt = require('evt'),
    model = require('model'),
    Cards = common.Cards,
    activityCallback = null;

require('sync');
require('wake_locks');

model.latestOnce('api', function(api) {
  // If our password is bad, we need to pop up a card to ask for the updated
  // password.
  api.onbadlogin = function(account, problem) {
    switch (problem) {
      case 'bad-user-or-pass':
        Cards.pushCard('setup_fix_password', 'default', 'animate',
                  { account: account, restoreCard: Cards.activeCardIndex },
                  'right');
        break;
      case 'imap-disabled':
        Cards.pushCard('setup_fix_gmail_imap', 'default', 'animate',
                  { account: account, restoreCard: Cards.activeCardIndex },
                  'right');
        break;
      case 'needs-app-pass':
        Cards.pushCard('setup_fix_gmail_twofactor', 'default', 'animate',
                  { account: account, restoreCard: Cards.activeCardIndex },
                  'right');
        break;
    }
  };

  api.useLocalizedStrings({
    wrote: mozL10n.get('reply-quoting-wrote'),
    originalMessage: mozL10n.get('forward-original-message'),
    forwardHeaderLabels: {
      subject: mozL10n.get('forward-header-subject'),
      date: mozL10n.get('forward-header-date'),
      from: mozL10n.get('forward-header-from'),
      replyTo: mozL10n.get('forward-header-reply-to'),
      to: mozL10n.get('forward-header-to'),
      cc: mozL10n.get('forward-header-cc')
    },
    folderNames: {
      inbox: mozL10n.get('folder-inbox'),
      sent: mozL10n.get('folder-sent'),
      drafts: mozL10n.get('folder-drafts'),
      trash: mozL10n.get('folder-trash'),
      queue: mozL10n.get('folder-queue'),
      junk: mozL10n.get('folder-junk'),
      archives: mozL10n.get('folder-archives'),
      localdrafts: mozL10n.get('folder-localdrafts')
    }
  });
});

// Handle cases where a default card is needed for back navigation
// after a non-default entry point (like an activity) is triggered.
Cards.pushDefaultCard = function(onPushed) {
  model.latestOnce('foldersSlice', function() {
    Cards.pushCard('message_list', 'nonsearch', 'none', {
      onPushed: onPushed
    },
    // Default to "before" placement.
    'left');
  });
};

Cards._init();

var finalCardStateCallback,
    waitForAppMessage = false,
    startedInBackground = false,
    cachedNode = Cards._cardsNode.children[0],
    startCardId = cachedNode && cachedNode.getAttribute('data-type');

var startCardArgs = {
  'setup_account_info': [
    'setup_account_info', 'default', 'immediate',
    {
      onPushed: function(impl) {
        htmlCache.delayedSaveFromNode(impl.domNode.cloneNode(true));
      }
    }
  ],
  'message_list': [
    'message_list', 'nonsearch', 'immediate', {}
  ]
};

function pushStartCard(id, addedArgs) {
  var args = startCardArgs[id];
  if (!args)
    throw new Error('Invalid start card: ' + id);

  //Add in cached node to use (could be null)
  args[3].cachedNode = cachedNode;

  // Mix in addedArgs to the args object that is passed to pushCard.
  if (addedArgs) {
    Object.keys(addedArgs).forEach(function(key) {
      args[3][key] = addedArgs[key];
    });
  }

  return Cards.pushCard.apply(Cards, args);
}

if (appMessages.hasPending('activity') ||
    appMessages.hasPending('notification')) {
  // There is an activity, do not use the cache node, start fresh,
  // and block normal first card selection, wait for activity.
  cachedNode = null;
  waitForAppMessage = true;
}

if (appMessages.hasPending('alarm')) {
  // There is an alarm, do not use the cache node, start fresh,
  // as we were woken up just for the alarm.
  cachedNode = null;
  startedInBackground = true;
}

// If still have a cached node, then show it.
if (cachedNode) {
  // Wire up a card implementation to the cached node.
  if (startCardId) {
    pushStartCard(startCardId);
  } else {
    cachedNode = null;
  }
}

/**
 * When determination of real start state is known after
 * getting data, then make sure the correct card is
 * shown. If the card used from cache is not correct,
 * wipe out the cards and start fresh.
 * @param  {String} cardId the desired card ID.
 */
function resetCards(cardId, args) {
  cachedNode = null;

  var startArgs = startCardArgs[cardId],
      query = [startArgs[0], startArgs[1]];

  if (!Cards.hasCard(query)) {
    Cards.removeAllCards();
    pushStartCard(cardId, args);
  }
}

/**
 * Tracks what final card state should be shown. If the
 * app started up hidden for a cronsync, do not actually
 * show the UI until the app becomes visible, so that
 * extra work can be avoided for the hidden cronsync case.
 */
function showFinalCardState(fn) {
  if (startedInBackground && document.hidden) {
    finalCardStateCallback = fn;
  } else {
    fn();
  }
}

/**
 * Shows the message list. Assumes that the correct
 * account and inbox have already been selected.
 */
function showMessageList(args) {
  showFinalCardState(function() {
    resetCards('message_list', args);
  });
}

// Handles visibility changes: if the app becomes visible
// being hidden via a cronsync startup, trigger UI creation.
document.addEventListener('visibilitychange', function onVisibilityChange() {
  if (startedInBackground && finalCardStateCallback && !document.hidden) {
    finalCardStateCallback();
    finalCardStateCallback = null;
  }
}, false);

// Some event modifications during setup do not have full account
// IDs. This listener catches those modifications and applies
// them when the data is available.
evt.on('accountModified', function(accountId, data) {
  model.latestOnce('acctsSlice', function() {
    var account = model.getAccount(accountId);
    if (account)
      account.modifyAccount(data);
  });
});

// The add account UI flow is requested.
evt.on('addAccount', function() {
  Cards.removeAllCards();

  // Show the first setup card again.
  pushStartCard('setup_account_info', {
    allowBack: true
  });
});

function resetApp() {
  Cards.removeAllCards();
  model.init();
}

// An account was deleted. Burn it all to the ground and
// rise like a phoenix. Prefer a UI event vs. a slice
// listen to give flexibility about UI construction:
// an acctsSlice splice change may not warrant removing
// all the cards.
evt.on('accountDeleted', resetApp);
evt.on('resetApp', resetApp);

// A request to show the latest account in the UI.
// Usually triggered after an account has been added.
evt.on('showLatestAccount', function() {
  Cards.removeAllCards();

  model.latestOnce('acctsSlice', function(acctsSlice) {
    var account = acctsSlice.items[acctsSlice.items.length - 1];
    model.changeAccount(account, function() {
      pushStartCard('message_list');
    });
  });
});

model.on('acctsSlice', function() {
  if (!model.hasAccount()) {
    resetCards('setup_account_info');
  } else {
    model.latestOnce('foldersSlice', function() {
      if (waitForAppMessage)
        return;

      // If an activity was waiting for an account, trigger it now.
      if (activityCallback) {
        var activityCb = activityCallback;
        activityCallback = null;
        return activityCb();
      }

      showMessageList();
    });
  }
});

appMessages.on('activity', function(type, data, rawActivity) {

  function initComposer() {
    Cards.pushCard('compose', 'default', 'immediate', {
      activity: rawActivity,
      composerData: {
        onComposer: function(composer) {
          var attachmentBlobs = data.attachmentBlobs;
          /* to/cc/bcc/subject/body all have default values that shouldn't
          be clobbered if they are not specified in the URI*/
          if (data.to)
            composer.to = data.to;
          if (data.subject)
            composer.subject = data.subject;
          if (data.body)
            composer.body = { text: data.body };
          if (data.cc)
            composer.cc = data.cc;
          if (data.bcc)
            composer.bcc = data.bcc;
          if (attachmentBlobs) {
            for (var iBlob = 0; iBlob < attachmentBlobs.length; iBlob++) {
              composer.addAttachment({
                name: data.attachmentNames[iBlob],
                blob: attachmentBlobs[iBlob]
              });
            }
          }
        }
      }
    });
  }

  function promptEmptyAccount() {
    var req = confirm(mozL10n.get('setup-empty-account-prompt'));
    if (!req) {
      rawActivity.postError('cancelled');
    }

    // No longer need to wait for the activity to complete, it needs
    // normal card flow
    waitForAppMessage = false;

    activityCallback = initComposer;
  }

  if (model.inited) {
    if (model.hasAccount()) {
      initComposer();
    } else {
      promptEmptyAccount();
    }
  } else {
    // Be optimistic and start rendering compose as soon as possible
    // In the edge case that email is not configured, then the empty
    // account prompt will be triggered quickly in the next section.
    initComposer();

    model.latestOnce('acctsSlice', function activityOnAccount() {
      if (!model.hasAccount()) {
        promptEmptyAccount();
      }
    });
  }
});

appMessages.on('notification', function(data) {
  var type = data ? data.type : '';

  model.latestOnce('foldersSlice', function latestFolderSlice() {
    function onCorrectFolder() {
      function onPushed() {
        waitForAppMessage = false;
      }

      if (type === 'message_list') {
        showMessageList({
          onPushed: onPushed
        });
      } else if (type === 'message_reader') {
        Cards.pushCard(data.type, 'default', 'immediate', {
          messageSuid: data.messageSuid,
          backOnMissingMessage: true,
          onPushed: onPushed
        });
      } else {
        console.error('unhandled notification type: ' + type);
      }
    }

    var acctsSlice = model.acctsSlice,
        accountId = data.accountId;

    if (model.account.id === accountId) {
      return model.selectInbox(onCorrectFolder);
    } else {
      var newAccount;
      acctsSlice.items.some(function(account) {
        if (account.id === accountId) {
          newAccount = account;
          return true;
        }
      });

      if (newAccount) {
        model.changeAccount(newAccount, onCorrectFolder);
      }
    }
  });
});

model.init();
});

// Run the app module, bring in fancy logging
requirejs(['console_hook', 'cards/message_list', 'mail_app']);

/* -*- Mode: js; js-indent-level: 2; indent-tabs-mode: nil -*- */
/* vim: set shiftwidth=2 tabstop=2 autoindent cindent expandtab: */



/**
 * This library exposes a `navigator.mozL10n' object to handle client-side
 * application localization. See: https://github.com/fabi1cazenave/webL10n
 */

(function(window) {
  var gL10nData = {};
  var gLanguage = '';
  var gMacros = {};
  var gReadyState = 'loading';

  // DOM element properties that may be localized with a key:value pair.
  var gNestedProps = ['style', 'dataset'];


  /**
   * Localization resources are declared in the HTML document with <link> nodes:
   *   <link rel="prefetch" type="application/l10n" href="locales.ini" />
   * Such *.ini files are multi-locale dictionaries where all supported locales
   * are listed / defined / imported, and where a fallback locale can easily be
   * defined.
   *
   * These *.ini files can also be compiled to locale-specific JSON dictionaries
   * with the `getDictionary()' method.  Such JSON dictionaries can be used:
   *  - either with a <link> node:
   *   <link rel="prefetch" type="application/l10n" href="{{locale}}.json" />
   *   (in which case, {{locale}} will be replaced by `navigator.language')
   *  - or with an inline <script> node:
   *   <script type="application/l10n" lang="fr"> ... </script>
   *   (in which case, the script matching `navigator.language' will be parsed)
   *
   * This is where `gDefaultLocale' comes in: if a JSON dictionary for the
   * current `navigator.language' value can't be found, use the one matching the
   * default locale.  Note that if the <html> element has a `lang' attribute,
   * its value becomes the default locale.
   */

  var gDefaultLocale = 'en-US';


  /**
   * Synchronously loading l10n resources significantly minimizes flickering
   * from displaying the app with non-localized strings and then updating the
   * strings. Although this will block all script execution on this page, we
   * expect that the l10n resources are available locally on flash-storage.
   *
   * As synchronous XHR is generally considered as a bad idea, we're still
   * loading l10n resources asynchronously -- but we keep this in a setting,
   * just in case... and applications using this library should hide their
   * content until the `localized' event happens.
   */

  var gAsyncResourceLoading = true; // read-only


  /**
   * Debug helpers
   *
   *   gDEBUG == 0: don't display any console message
   *   gDEBUG == 1: display only warnings, not logs
   *   gDEBUG == 2: display all console messages
   */

  var gDEBUG = 1;

  function consoleLog(message) {
    if (gDEBUG >= 2) {
      console.log('[l10n] ' + message);
    }
  };

  function consoleWarn(message) {
    if (gDEBUG) {
      console.warn('[l10n] ' + message);
    }
  };

  function consoleWarn_missingKeys(untranslatedElements, lang) {
    var len = untranslatedElements.length;
    if (!len || !gDEBUG) {
      return;
    }

    var missingIDs = [];
    for (var i = 0; i < len; i++) {
      var l10nId = untranslatedElements[i].getAttribute('data-l10n-id');
      if (missingIDs.indexOf(l10nId) < 0) {
        missingIDs.push(l10nId);
      }
    }
    console.warn('[l10n] ' +
        missingIDs.length + ' missing key(s) for [' + lang + ']: ' +
        missingIDs.join(', '));
  }


  /**
   * DOM helpers for the so-called "HTML API".
   *
   * These functions are written for modern browsers. For old versions of IE,
   * they're overridden in the 'startup' section at the end of this file.
   */

  function getL10nResourceLinks() {
    return document.querySelectorAll('link[type="application/l10n"]');
  }

  function getL10nDictionary(lang) {
    var getInlineDict = function(locale) {
      var sel = 'script[type="application/l10n"][lang="' + locale + '"]';
      return document.querySelector(sel);
    };
    // TODO: support multiple internal JSON dictionaries
    var script = getInlineDict(lang) || getInlineDict(gDefaultLocale);
    return script ? JSON.parse(script.innerHTML) : null;
  }

  function getTranslatableChildren(element) {
    return element ? element.querySelectorAll('*[data-l10n-id]') : [];
  }

  function getL10nAttributes(element) {
    if (!element) {
      return {};
    }

    var l10nId = element.getAttribute('data-l10n-id');
    var l10nArgs = element.getAttribute('data-l10n-args');
    var args = {};
    if (l10nArgs) {
      try {
        args = JSON.parse(l10nArgs);
      } catch (e) {
        consoleWarn('could not parse arguments for #' + l10nId);
      }
    }
    return { id: l10nId, args: args };
  }

  function setTextContent(element, text) {
    // standard case: no element children
    if (!element.firstElementChild) {
      element.textContent = text;
      return;
    }

    // this element has element children: replace the content of the first
    // (non-blank) child textNode and clear other child textNodes
    var found = false;
    var reNotBlank = /\S/;
    for (var child = element.firstChild; child; child = child.nextSibling) {
      if (child.nodeType === 3 && reNotBlank.test(child.nodeValue)) {
        if (found) {
          child.nodeValue = '';
        } else {
          child.nodeValue = text;
          found = true;
        }
      }
    }
    // if no (non-empty) textNode is found, insert a textNode before the
    // element's first child.
    if (!found) {
      element.insertBefore(document.createTextNode(text), element.firstChild);
    }
  }

  function fireL10nReadyEvent() {
    var evtObject = document.createEvent('Event');
    evtObject.initEvent('localized', false, false);
    evtObject.language = gLanguage;
    window.dispatchEvent(evtObject);
  }


  /**
   * l10n resource parser:
   *  - reads (async XHR) the l10n resource matching `lang';
   *  - imports linked resources (synchronously) when specified;
   *  - parses the text data (fills `gL10nData');
   *  - triggers success/failure callbacks when done.
   *
   * @param {string} href
   *    URL of the l10n resource to parse.
   *
   * @param {string} lang
   *    locale (language) to parse.
   *
   * @param {Function} successCallback
   *    triggered when the l10n resource has been successully parsed.
   *
   * @param {Function} failureCallback
   *    triggered when the an error has occured.
   *
   * @return {void}
   *    fills gL10nData.
   */

  function parseResource(href, lang, successCallback, failureCallback) {
    var baseURL = href.replace(/\/[^\/]*$/, '/');

    // handle escaped characters (backslashes) in a string
    function evalString(text) {
      if (text.lastIndexOf('\\') < 0) {
        return text;
      }
      return text.replace(/\\\\/g, '\\')
                 .replace(/\\n/g, '\n')
                 .replace(/\\r/g, '\r')
                 .replace(/\\t/g, '\t')
                 .replace(/\\b/g, '\b')
                 .replace(/\\f/g, '\f')
                 .replace(/\\{/g, '{')
                 .replace(/\\}/g, '}')
                 .replace(/\\"/g, '"')
                 .replace(/\\'/g, "'");
    }

    // parse *.properties text data into an l10n dictionary
    function parseProperties(text) {
      var dictionary = [];

      // token expressions
      var reBlank = /^\s*|\s*$/;
      var reComment = /^\s*#|^\s*$/;
      var reSection = /^\s*\[(.*)\]\s*$/;
      var reImport = /^\s*@import\s+url\((.*)\)\s*$/i;
      var reSplit = /^([^=\s]*)\s*=\s*(.+)$/;
      var reUnicode = /\\u([0-9a-fA-F]{1,4})/g;
      var reMultiline = /[^\\]\\$/;

      // parse the *.properties file into an associative array
      function parseRawLines(rawText, extendedSyntax) {
        var entries = rawText.replace(reBlank, '').split(/[\r\n]+/);
        var currentLang = '*';
        var genericLang = lang.replace(/-[a-z]+$/i, '');
        var skipLang = false;
        var match = '';

        for (var i = 0; i < entries.length; i++) {
          var line = entries[i];

          // comment or blank line?
          if (reComment.test(line)) {
            continue;
          }

          // multi-line?
          while (reMultiline.test(line) && i < entries.length) {
            line = line.slice(0, line.length - 1) +
              entries[++i].replace(reBlank, '');
          }

          // the extended syntax supports [lang] sections and @import rules
          if (extendedSyntax) {
            if (reSection.test(line)) { // section start?
              match = reSection.exec(line);
              currentLang = match[1];
              skipLang = (currentLang !== '*') &&
                  (currentLang !== lang) && (currentLang !== genericLang);
              continue;
            } else if (skipLang) {
              continue;
            }
            if (reImport.test(line)) { // @import rule?
              match = reImport.exec(line);
              loadImport(baseURL + match[1]); // load the resource synchronously
            }
          }

          // key-value pair
          var tmp = line.match(reSplit);
          if (tmp && tmp.length == 3) {
            // unescape unicode char codes if needed (e.g. '\u00a0')
            var val = tmp[2].replace(reUnicode, function(match, token) {
              return unescape('%u' + '0000'.slice(token.length) + token);
            });
            dictionary[tmp[1]] = evalString(val);
          }
        }
      }

      // import another *.properties file
      function loadImport(url) {
        loadResource(url, function(content) {
          parseRawLines(content, false); // don't allow recursive imports
        }, null, false); // load synchronously
      }

      // fill the dictionary
      parseRawLines(text, true);
      return dictionary;
    }

    // load the specified resource file
    function loadResource(url, onSuccess, onFailure, asynchronous) {
      onSuccess = onSuccess || function _onSuccess(data) {};
      onFailure = onFailure || function _onFailure() {
        consoleWarn(url + ' not found.');
      };

      var xhr = new XMLHttpRequest();
      xhr.open('GET', url, asynchronous);
      if (xhr.overrideMimeType) {
        xhr.overrideMimeType('text/plain; charset=utf-8');
      }
      xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
          if (xhr.status == 200 || xhr.status === 0) {
            onSuccess(xhr.responseText);
          } else {
            onFailure();
          }
        }
      };
      xhr.onerror = onFailure;
      xhr.ontimeout = onFailure;

      // in Firefox OS with the app:// protocol, trying to XHR a non-existing
      // URL will raise an exception here -- hence this ugly try...catch.
      try {
        xhr.send(null);
      } catch (e) {
        onFailure();
      }
    }

    // load and parse l10n data (warning: global variables are used here)
    loadResource(href, function(response) {
      if (/\.json$/.test(href)) {
        gL10nData = JSON.parse(response); // TODO: support multiple JSON files
      } else { // *.ini or *.properties file
        var data = parseProperties(response);
        for (var key in data) {
          var id, prop, nestedProp, index = key.lastIndexOf('.');
          if (index > 0) { // a property name has been specified
            id = key.slice(0, index);
            prop = key.slice(index + 1);
            index = id.lastIndexOf('.');
            if (index > 0) { // a nested property may have been specified
              nestedProp = id.substr(index + 1);
              if (gNestedProps.indexOf(nestedProp) > -1) {
                id = id.substr(0, index);
                prop = nestedProp + '.' + prop;
              }
            }
          } else { // no property name: assuming text content by default
            index = key.lastIndexOf('[');
            if (index > 0) { // we have a macro index
              id = key.slice(0, index);
              prop = '_' + key.slice(index);
            } else {
              id = key;
              prop = '_';
            }
          }
          if (!gL10nData[id]) {
            gL10nData[id] = {};
          }
          gL10nData[id][prop] = data[key];
        }
      }

      // trigger callback
      if (successCallback) {
        successCallback();
      }
    }, failureCallback, gAsyncResourceLoading);
  };

  // load and parse all resources for the specified locale
  function loadLocale(lang, translationRequired) {
    clear();
    gReadyState = 'loading';
    gLanguage = lang;

    var untranslatedElements = [];

    // if there is an inline / pre-compiled dictionary,
    // the current HTML document can be translated right now
    var inlineDict = getL10nDictionary(lang);
    if (inlineDict) {
      gL10nData = inlineDict;
      if (translationRequired) {
        untranslatedElements = translateFragment();
      }
    }

    // translate the document if required and fire a `localized' event
    function finish() {
      if (translationRequired) {
        if (!inlineDict) {
          // no inline dictionary has been used: translate the whole document
          untranslatedElements = translateFragment();
        } else if (untranslatedElements.length) {
          // the document should have been already translated but the inline
          // dictionary didn't include all necessary l10n keys:
          // try to translate all remaining elements now
          untranslatedElements = translateElements(untranslatedElements);
        }
      }
      // tell the rest of the world we're done
      // -- note that `gReadyState' must be set before the `localized' event is
      //    fired for `localizeElement()' to work as expected
      gReadyState = 'complete';
      fireL10nReadyEvent(lang);
      consoleWarn_missingKeys(untranslatedElements, lang);
    }

    // l10n resource loader
    function l10nResourceLink(link) {
      /**
       * l10n resource links can use the following syntax for href:
       * <link type="application/l10n" href="resources/{{locale}}.json" />
       * -- in which case, {{locale}} will be replaced by `navigator.language'.
       */
      var re = /\{\{\s*locale\s*\}\}/;

      var parse = function(locale, onload, onerror) {
        var href = unescape(link.href).replace(re, locale);
        parseResource(href, locale, onload, function notFound() {
          consoleWarn(href + ' not found.');
          onerror();
        });
      };

      this.load = function(locale, onload, onerror) {
        onerror = onerror || function() {};
        parse(locale, onload, function parseFallbackLocale() {
          /**
           * For links like <link href="resources/{{locale}}.json" />,
           * there's no way to know if the resource file matching the current
           * language has been found... before trying to fetch it with XHR
           * => if something went wrong, try the default locale as fallback.
           */
          if (re.test(unescape(link.href)) && gDefaultLocale != locale) {
            consoleLog('Trying the fallback locale: ' + gDefaultLocale);
            parse(gDefaultLocale, onload, onerror);
          } else {
            onerror();
          }
        });
      };
    }

    // check all <link type="application/l10n" href="..." /> nodes
    // and load the resource files
    var resourceLinks = getL10nResourceLinks();
    var resourceCount = resourceLinks.length;
    if (!resourceCount) {
      consoleLog('no resource to load, early way out');
      translationRequired = false;
      finish();
    } else {
      var onResourceCallback = function() {
        if (--resourceCount <= 0) { // <=> all resources have been XHR'ed
          finish();
        }
      };
      for (var i = 0, l = resourceCount; i < l; i++) {
        var resource = new l10nResourceLink(resourceLinks[i]);
        resource.load(lang, onResourceCallback, onResourceCallback);
      }
    }
  }

  // clear all l10n data
  function clear() {
    gL10nData = {};
    gLanguage = '';
    // TODO: clear all non predefined macros.
    // There's no such macro /yet/ but we're planning to have some...
  }


  /**
   * Get rules for plural forms (shared with JetPack), see:
   * http://unicode.org/repos/cldr-tmp/trunk/diff/supplemental/language_plural_rules.html
   * https://github.com/mozilla/addon-sdk/blob/master/python-lib/plural-rules-generator.p
   *
   * @param {string} lang
   *    locale (language) used.
   *
   * @return {Function}
   *    returns a function that gives the plural form name for a given integer:
   *       var fun = getPluralRules('en');
   *       fun(1)    -> 'one'
   *       fun(0)    -> 'other'
   *       fun(1000) -> 'other'.
   */

  var kPluralForms = ['zero', 'one', 'two', 'few', 'many', 'other'];

  function getPluralRules(lang) {
    var locales2rules = {
      'af': 3,
      'ak': 4,
      'am': 4,
      'ar': 1,
      'asa': 3,
      'az': 0,
      'be': 11,
      'bem': 3,
      'bez': 3,
      'bg': 3,
      'bh': 4,
      'bm': 0,
      'bn': 3,
      'bo': 0,
      'br': 20,
      'brx': 3,
      'bs': 11,
      'ca': 3,
      'cgg': 3,
      'chr': 3,
      'cs': 12,
      'cy': 17,
      'da': 3,
      'de': 3,
      'dv': 3,
      'dz': 0,
      'ee': 3,
      'el': 3,
      'en': 3,
      'eo': 3,
      'es': 3,
      'et': 3,
      'eu': 3,
      'fa': 0,
      'ff': 5,
      'fi': 3,
      'fil': 4,
      'fo': 3,
      'fr': 5,
      'fur': 3,
      'fy': 3,
      'ga': 8,
      'gd': 24,
      'gl': 3,
      'gsw': 3,
      'gu': 3,
      'guw': 4,
      'gv': 23,
      'ha': 3,
      'haw': 3,
      'he': 2,
      'hi': 4,
      'hr': 11,
      'hu': 0,
      'id': 0,
      'ig': 0,
      'ii': 0,
      'is': 3,
      'it': 3,
      'iu': 7,
      'ja': 0,
      'jmc': 3,
      'jv': 0,
      'ka': 0,
      'kab': 5,
      'kaj': 3,
      'kcg': 3,
      'kde': 0,
      'kea': 0,
      'kk': 3,
      'kl': 3,
      'km': 0,
      'kn': 0,
      'ko': 0,
      'ksb': 3,
      'ksh': 21,
      'ku': 3,
      'kw': 7,
      'lag': 18,
      'lb': 3,
      'lg': 3,
      'ln': 4,
      'lo': 0,
      'lt': 10,
      'lv': 6,
      'mas': 3,
      'mg': 4,
      'mk': 16,
      'ml': 3,
      'mn': 3,
      'mo': 9,
      'mr': 3,
      'ms': 0,
      'mt': 15,
      'my': 0,
      'nah': 3,
      'naq': 7,
      'nb': 3,
      'nd': 3,
      'ne': 3,
      'nl': 3,
      'nn': 3,
      'no': 3,
      'nr': 3,
      'nso': 4,
      'ny': 3,
      'nyn': 3,
      'om': 3,
      'or': 3,
      'pa': 3,
      'pap': 3,
      'pl': 13,
      'ps': 3,
      'pt': 3,
      'rm': 3,
      'ro': 9,
      'rof': 3,
      'ru': 11,
      'rwk': 3,
      'sah': 0,
      'saq': 3,
      'se': 7,
      'seh': 3,
      'ses': 0,
      'sg': 0,
      'sh': 11,
      'shi': 19,
      'sk': 12,
      'sl': 14,
      'sma': 7,
      'smi': 7,
      'smj': 7,
      'smn': 7,
      'sms': 7,
      'sn': 3,
      'so': 3,
      'sq': 3,
      'sr': 11,
      'ss': 3,
      'ssy': 3,
      'st': 3,
      'sv': 3,
      'sw': 3,
      'syr': 3,
      'ta': 3,
      'te': 3,
      'teo': 3,
      'th': 0,
      'ti': 4,
      'tig': 3,
      'tk': 3,
      'tl': 4,
      'tn': 3,
      'to': 0,
      'tr': 0,
      'ts': 3,
      'tzm': 22,
      'uk': 11,
      'ur': 3,
      've': 3,
      'vi': 0,
      'vun': 3,
      'wa': 4,
      'wae': 3,
      'wo': 0,
      'xh': 3,
      'xog': 3,
      'yo': 0,
      'zh': 0,
      'zu': 3
    };

    // utility functions for plural rules methods
    function isIn(n, list) {
      return list.indexOf(n) !== -1;
    }
    function isBetween(n, start, end) {
      return start <= n && n <= end;
    }

    // list of all plural rules methods:
    // map an integer to the plural form name to use
    var pluralRules = {
      '0': function(n) {
        return 'other';
      },
      '1': function(n) {
        if ((isBetween((n % 100), 3, 10)))
          return 'few';
        if (n === 0)
          return 'zero';
        if ((isBetween((n % 100), 11, 99)))
          return 'many';
        if (n == 2)
          return 'two';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '2': function(n) {
        if (n !== 0 && (n % 10) === 0)
          return 'many';
        if (n == 2)
          return 'two';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '3': function(n) {
        if (n == 1)
          return 'one';
        return 'other';
      },
      '4': function(n) {
        if ((isBetween(n, 0, 1)))
          return 'one';
        return 'other';
      },
      '5': function(n) {
        if ((isBetween(n, 0, 2)) && n != 2)
          return 'one';
        return 'other';
      },
      '6': function(n) {
        if (n === 0)
          return 'zero';
        if ((n % 10) == 1 && (n % 100) != 11)
          return 'one';
        return 'other';
      },
      '7': function(n) {
        if (n == 2)
          return 'two';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '8': function(n) {
        if ((isBetween(n, 3, 6)))
          return 'few';
        if ((isBetween(n, 7, 10)))
          return 'many';
        if (n == 2)
          return 'two';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '9': function(n) {
        if (n === 0 || n != 1 && (isBetween((n % 100), 1, 19)))
          return 'few';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '10': function(n) {
        if ((isBetween((n % 10), 2, 9)) && !(isBetween((n % 100), 11, 19)))
          return 'few';
        if ((n % 10) == 1 && !(isBetween((n % 100), 11, 19)))
          return 'one';
        return 'other';
      },
      '11': function(n) {
        if ((isBetween((n % 10), 2, 4)) && !(isBetween((n % 100), 12, 14)))
          return 'few';
        if ((n % 10) === 0 ||
            (isBetween((n % 10), 5, 9)) ||
            (isBetween((n % 100), 11, 14)))
          return 'many';
        if ((n % 10) == 1 && (n % 100) != 11)
          return 'one';
        return 'other';
      },
      '12': function(n) {
        if ((isBetween(n, 2, 4)))
          return 'few';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '13': function(n) {
        if ((isBetween((n % 10), 2, 4)) && !(isBetween((n % 100), 12, 14)))
          return 'few';
        if (n != 1 && (isBetween((n % 10), 0, 1)) ||
            (isBetween((n % 10), 5, 9)) ||
            (isBetween((n % 100), 12, 14)))
          return 'many';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '14': function(n) {
        if ((isBetween((n % 100), 3, 4)))
          return 'few';
        if ((n % 100) == 2)
          return 'two';
        if ((n % 100) == 1)
          return 'one';
        return 'other';
      },
      '15': function(n) {
        if (n === 0 || (isBetween((n % 100), 2, 10)))
          return 'few';
        if ((isBetween((n % 100), 11, 19)))
          return 'many';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '16': function(n) {
        if ((n % 10) == 1 && n != 11)
          return 'one';
        return 'other';
      },
      '17': function(n) {
        if (n == 3)
          return 'few';
        if (n === 0)
          return 'zero';
        if (n == 6)
          return 'many';
        if (n == 2)
          return 'two';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '18': function(n) {
        if (n === 0)
          return 'zero';
        if ((isBetween(n, 0, 2)) && n !== 0 && n != 2)
          return 'one';
        return 'other';
      },
      '19': function(n) {
        if ((isBetween(n, 2, 10)))
          return 'few';
        if ((isBetween(n, 0, 1)))
          return 'one';
        return 'other';
      },
      '20': function(n) {
        if ((isBetween((n % 10), 3, 4) || ((n % 10) == 9)) && !(
            isBetween((n % 100), 10, 19) ||
            isBetween((n % 100), 70, 79) ||
            isBetween((n % 100), 90, 99)
            ))
          return 'few';
        if ((n % 1000000) === 0 && n !== 0)
          return 'many';
        if ((n % 10) == 2 && !isIn((n % 100), [12, 72, 92]))
          return 'two';
        if ((n % 10) == 1 && !isIn((n % 100), [11, 71, 91]))
          return 'one';
        return 'other';
      },
      '21': function(n) {
        if (n === 0)
          return 'zero';
        if (n == 1)
          return 'one';
        return 'other';
      },
      '22': function(n) {
        if ((isBetween(n, 0, 1)) || (isBetween(n, 11, 99)))
          return 'one';
        return 'other';
      },
      '23': function(n) {
        if ((isBetween((n % 10), 1, 2)) || (n % 20) === 0)
          return 'one';
        return 'other';
      },
      '24': function(n) {
        if ((isBetween(n, 3, 10) || isBetween(n, 13, 19)))
          return 'few';
        if (isIn(n, [2, 12]))
          return 'two';
        if (isIn(n, [1, 11]))
          return 'one';
        return 'other';
      }
    };

    // return a function that gives the plural form name for a given integer
    var index = locales2rules[lang.replace(/-.*$/, '')];
    if (!(index in pluralRules)) {
      consoleWarn('plural form unknown for [' + lang + ']');
      return function() { return 'other'; };
    }
    return pluralRules[index];
  }

  // pre-defined 'plural' macro
  gMacros.plural = function(str, param, key, prop) {
    var n = parseFloat(param);
    if (isNaN(n)) {
      return str;
    }

    var data = gL10nData[key];
    if (!data) {
      return str;
    }

    // initialize _pluralRules
    if (!gMacros._pluralRules) {
      gMacros._pluralRules = getPluralRules(gLanguage);
    }
    var index = '[' + gMacros._pluralRules(n) + ']';

    // try to find a [zero|one|two] form if it's defined
    if (n === 0 && (prop + '[zero]') in data) {
      str = data[prop + '[zero]'];
    } else if (n == 1 && (prop + '[one]') in data) {
      str = data[prop + '[one]'];
    } else if (n == 2 && (prop + '[two]') in data) {
      str = data[prop + '[two]'];
    } else if ((prop + index) in data) {
      str = data[prop + index];
    } else if ((prop + '[other]') in data) {
      str = data[prop + '[other]'];
    }

    return str;
  };


  /**
   * l10n dictionary functions
   */

  var reArgs = /\{\{\s*(.+?)\s*\}\}/;                       // arguments
  var reIndex = /\{\[\s*([a-zA-Z]+)\(([a-zA-Z]+)\)\s*\]\}/; // index macros

  // fetch an l10n object, warn if not found, apply `args' if possible
  function getL10nData(key, args) {
    var data = gL10nData[key];
    if (!data) {
      return null;
    }

    /**
     * This is where l10n expressions should be processed.
     * The plan is to support C-style expressions from the l20n project;
     * until then, only two kinds of simple expressions are supported:
     *   {[ index ]} and {{ arguments }}.
     */
    var rv = {};
    for (var prop in data) {
      var str = data[prop];
      str = substIndexes(str, args, key, prop);
      str = substArguments(str, args, key);
      rv[prop] = str;
    }
    return rv;
  }

  // return an array of all {{arguments}} found in a string
  function getL10nArgs(str) {
    var args = [];
    var match = reArgs.exec(str);
    while (match && match.length >= 2) {
      args.push({
        name: match[1], // name of the argument
        subst: match[0] // substring to replace (including braces and spaces)
      });
      str = str.substr(match.index + match[0].length);
      match = reArgs.exec(str);
    }
    return args;
  }

  // return a sub-dictionary sufficient to translate a given fragment
  function getSubDictionary(fragment) {
    if (!fragment) { // by default, return a clone of the whole dictionary
      return JSON.parse(JSON.stringify(gL10nData));
    }

    var dict = {};
    var elements = getTranslatableChildren(fragment);

    function checkGlobalArguments(str) {
      var match = getL10nArgs(str);
      for (var i = 0; i < match.length; i++) {
        var arg = match[i].name;
        if (arg in gL10nData) {
          dict[arg] = gL10nData[arg];
        }
      }
    }

    for (var i = 0, l = elements.length; i < l; i++) {
      var id = getL10nAttributes(elements[i]).id;
      var data = gL10nData[id];
      if (!id || !data) {
        continue;
      }

      dict[id] = data;
      for (var prop in data) {
        var str = data[prop];
        checkGlobalArguments(str);

        if (reIndex.test(str)) { // macro index
          for (var j = 0; j < kPluralForms.length; j++) {
            var key = id + '[' + kPluralForms[j] + ']';
            if (key in gL10nData) {
              dict[key] = gL10nData[key];
              checkGlobalArguments(gL10nData[key]);
            }
          }
        }
      }
    }

    return dict;
  }

  // replace {[macros]} with their values
  function substIndexes(str, args, key, prop) {
    var reMatch = reIndex.exec(str);
    if (!reMatch || !reMatch.length) {
      return str;
    }

    // an index/macro has been found
    // Note: at the moment, only one parameter is supported
    var macroName = reMatch[1];
    var paramName = reMatch[2];
    var param;
    if (args && paramName in args) {
      param = args[paramName];
    } else if (paramName in gL10nData) {
      param = gL10nData[paramName];
    }

    // there's no macro parser yet: it has to be defined in gMacros
    if (macroName in gMacros) {
      var macro = gMacros[macroName];
      str = macro(str, param, key, prop);
    }
    return str;
  }

  // replace {{arguments}} with their values
  function substArguments(str, args, key) {
    var match = getL10nArgs(str);
    for (var i = 0; i < match.length; i++) {
      var sub, arg = match[i].name;
      if (args && arg in args) {
        sub = args[arg];
      } else if (arg in gL10nData) {
        sub = gL10nData[arg]['_'];
      } else {
        consoleLog('argument {{' + arg + '}} for #' + key + ' is undefined.');
        return str;
      }
      str = str.replace(match[i].subst, sub);
    }
    return str;
  }

  // translate an HTML element
  // -- returns true if the element could be translated, false otherwise
  function translateElement(element) {
    var l10n = getL10nAttributes(element);
    if (!l10n.id) {
      return true;
    }

    // get the related l10n object
    var data = getL10nData(l10n.id, l10n.args);
    if (!data) {
      return false;
    }

    // translate element (TODO: security checks?)
    for (var k in data) {
      if (k === '_') {
        setTextContent(element, data._);
      } else {
        var idx = k.lastIndexOf('.');
        var nestedProp = k.substr(0, idx);
        if (gNestedProps.indexOf(nestedProp) > -1) {
          element[nestedProp][k.substr(idx + 1)] = data[k];
        } else {
          element[k] = data[k];
        }
      }
    }
    return true;
  }

  // translate an array of HTML elements
  // -- returns an array of elements that could not be translated
  function translateElements(elements) {
    var untranslated = [];
    for (var i = 0, l = elements.length; i < l; i++) {
      if (!translateElement(elements[i])) {
        untranslated.push(elements[i]);
      }
    }
    return untranslated;
  }

  // translate an HTML subtree
  // -- returns an array of elements that could not be translated
  function translateFragment(element) {
    element = element || document.documentElement;
    var untranslated = translateElements(getTranslatableChildren(element));
    if (!translateElement(element)) {
      untranslated.push(element);
    }
    return untranslated;
  }

  // localize an element as soon as mozL10n is ready
  function localizeElement(element, id, args) {
    if (!element || !id) {
      return;
    }

    // set the data-l10n-[id|args] attributes
    element.setAttribute('data-l10n-id', id);
    if (args && typeof args === 'object') {
      element.setAttribute('data-l10n-args', JSON.stringify(args));
    } else {
      element.removeAttribute('data-l10n-args');
    }

    // if l10n resources are ready, translate now;
    // if not, the element will be translated along with the document anyway.
    if (gReadyState === 'complete') {
      translateElement(element);
    }
  }


  /**
   * Startup & Public API
   *
   * This section is quite specific to the B2G project: old browsers are not
   * supported and the API is slightly different from the standard webl10n one.
   */

  // load the default locale on startup
  function l10nStartup() {
    gDefaultLocale = document.documentElement.lang || gDefaultLocale;
    gReadyState = 'interactive';
    consoleLog('loading [' + navigator.language + '] resources, ' +
        (gAsyncResourceLoading ? 'asynchronously.' : 'synchronously.'));

    // load the default locale and translate the document if required
    var translationRequired =
      (document.documentElement.lang !== navigator.language);
    loadLocale(navigator.language, translationRequired);
  }

  // the B2G build system doesn't expose any `document'...
  if (typeof(document) !== 'undefined') {
    if (document.readyState === 'complete' ||
      document.readyState === 'interactive') {
      window.setTimeout(l10nStartup);
    } else {
      document.addEventListener('DOMContentLoaded', l10nStartup);
    }
  }

  // load the appropriate locale if the language setting has changed
  if ('mozSettings' in navigator && navigator.mozSettings) {
    navigator.mozSettings.addObserver('language.current', function(event) {
      loadLocale(event.settingValue, true);
    });
  }

  // public API
  navigator.mozL10n = {
    // get a localized string
    get: function l10n_get(key, args) {
      var data = getL10nData(key, args);
      if (!data) {
        consoleWarn('#' + key + ' is undefined.');
        return '';
      } else {
        return data._;
      }
    },

    // get|set the document language and direction
    get language() {
      return {
        // get|set the document language (ISO-639-1)
        get code() { return gLanguage; },
        set code(lang) { loadLocale(lang, true); },

        // get the direction (ltr|rtl) of the current language
        get direction() {
          // http://www.w3.org/International/questions/qa-scripts
          // Arabic, Hebrew, Farsi, Pashto, Urdu
          var rtlList = ['ar', 'he', 'fa', 'ps', 'ur'];
          return (rtlList.indexOf(gLanguage) >= 0) ? 'rtl' : 'ltr';
        }
      };
    },

    // translate an element or document fragment
    translate: translateFragment,

    // localize an element (= set its data-l10n-* attributes and translate it)
    localize: localizeElement,

    // get (a part of) the dictionary for the current locale
    getDictionary: getSubDictionary,

    // this can be used to prevent race conditions
    get readyState() { return gReadyState; },
    ready: function l10n_ready(callback) {
      if (!callback) {
        return;
      }
      if (gReadyState == 'complete') {
        window.setTimeout(callback);
      } else {
        window.addEventListener('localized', callback);
      }
    }
  };

  consoleLog('library loaded.');
})(this);


define("l10nbase", function(){});

/* -*- Mode: js; js-indent-level: 2; indent-tabs-mode: nil -*- */
/* vim: set shiftwidth=2 tabstop=2 autoindent cindent expandtab: */



/**
 * This lib relies on `l10n.js' to implement localizable date/time strings.
 *
 * The proposed `DateTimeFormat' object should provide all the features that are
 * planned for the `Intl.DateTimeFormat' constructor, but the API does not match
 * exactly the ES-i18n draft.
 *   - https://bugzilla.mozilla.org/show_bug.cgi?id=769872
 *   - http://wiki.ecmascript.org/doku.php?id=globalization:specification_drafts
 *
 * Besides, this `DateTimeFormat' object provides two features that aren't
 * planned in the ES-i18n spec:
 *   - a `toLocaleFormat()' that really works (i.e. fully translated);
 *   - a `fromNow()' method to handle relative dates ("pretty dates").
 *
 * WARNING: this library relies on the non-standard `toLocaleFormat()' method,
 * which is specific to Firefox -- no other browser is supported.
 */

navigator.mozL10n.DateTimeFormat = function(locales, options) {
  var _ = navigator.mozL10n.get;

  // https://developer.mozilla.org/en-US/docs/JavaScript/Reference/Global_Objects/Date/toLocaleFormat
  function localeFormat(d, format) {
    var tokens = format.match(/(%E.|%O.|%.)/g);

    for (var i = 0; tokens && i < tokens.length; i++) {
      var value = '';

      // http://pubs.opengroup.org/onlinepubs/007908799/xsh/strftime.html
      switch (tokens[i]) {
        // localized day/month names
        case '%a':
          value = _('weekday-' + d.getDay() + '-short');
          break;
        case '%A':
          value = _('weekday-' + d.getDay() + '-long');
          break;
        case '%b':
        case '%h':
          value = _('month-' + d.getMonth() + '-short');
          break;
        case '%B':
          value = _('month-' + d.getMonth() + '-long');
          break;
        case '%Eb':
          value = _('month-' + d.getMonth() + '-genitive');
          break;

        // like %H, but in 12-hour format and without any leading zero
        case '%I':
          value = d.getHours() % 12 || 12;
          break;

        // like %d, without any leading zero
        case '%e':
          value = d.getDate();
          break;

        // like %d, without any leading zero
        case '%p':
          value = d.getHours() < 12 ? 'AM' : 'PM';
          break;

        // localized date/time strings
        case '%c':
        case '%x':
        case '%X':
          // ensure the localized format string doesn't contain any %c|%x|%X
          var tmp = _('dateTimeFormat_' + tokens[i]);
          if (tmp && !(/(%c|%x|%X)/).test(tmp)) {
            value = localeFormat(d, tmp);
          }
          break;

        // other tokens don't require any localization
      }

      format = format.replace(tokens[i], value || d.toLocaleFormat(tokens[i]));
    }

    return format;
  }

  /**
   * Returns the parts of a number of seconds
   */
  function relativeParts(seconds) {
    seconds = Math.abs(seconds);
    var descriptors = {};
    var units = [
      'years', 86400 * 365,
      'months', 86400 * 30,
      'weeks', 86400 * 7,
      'days', 86400,
      'hours', 3600,
      'minutes', 60
    ];

    if (seconds < 60) {
      return {
        minutes: Math.round(seconds / 60)
      };
    }

    for (var i = 0, uLen = units.length; i < uLen; i += 2) {
      var value = units[i + 1];
      if (seconds >= value) {
        descriptors[units[i]] = Math.floor(seconds / value);
        seconds -= descriptors[units[i]] * value;
      }
    }
    return descriptors;
  }

  /**
   * Returns a translated string which respresents the
   * relative time before or after a date.
   * @param {String|Date} time before/after the currentDate.
   * @param {String} useCompactFormat whether to use a compact display format.
   * @param {Number} maxDiff returns a formatted date if the diff is greater.
   */
  function prettyDate(time, useCompactFormat, maxDiff) {
    maxDiff = maxDiff || 86400 * 10; // default = 10 days

    switch (time.constructor) {
      case String: // timestamp
        time = parseInt(time);
        break;
      case Date:
        time = time.getTime();
        break;
    }

    var secDiff = (Date.now() - time) / 1000;
    if (isNaN(secDiff)) {
      return _('incorrectDate');
    }

    if (secDiff > maxDiff) {
      return localeFormat(new Date(time), '%x');
    }

    var f = useCompactFormat ? '-short' : '-long';
    var parts = relativeParts(secDiff);

    var affix = secDiff >= 0 ? '-ago' : '-until';
    for (var i in parts) {
      return _(i + affix + f, { value: parts[i]});
    }
  }

  // API
  return {
    localeDateString: function localeDateString(d) {
      return localeFormat(d, '%x');
    },
    localeTimeString: function localeTimeString(d) {
      return localeFormat(d, '%X');
    },
    localeString: function localeString(d) {
      return localeFormat(d, '%c');
    },
    localeFormat: localeFormat,
    fromNow: prettyDate,
    relativeParts: relativeParts
  };
};

define("l10ndate", function(){});

define('text',{
  load: function(name, req, onload, config) {
    var url = req.toUrl(name),
        xhr = new XMLHttpRequest();

    xhr.open('GET', url, true);
    xhr.onreadystatechange = function(evt) {
      var status, err;
      if (xhr.readyState === 4) {
        status = xhr.status;
        if (status > 399 && status < 600) {
          //An http 4xx or 5xx error. Signal an error.
          err = new Error(url + ' HTTP status: ' + status);
          err.xhr = xhr;
          onload.error(err);
        } else {
          onload(xhr.responseText);
        }
      }
    };
    xhr.send(null);
  }
});


/* -*- Mode: Java; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- /
/* vim: set shiftwidth=2 tabstop=2 autoindent cindent expandtab: */



/**
 * GestureDetector.js: generate events for one and two finger gestures.
 *
 * A GestureDetector object listens for touch and mouse events on a specified
 * element and generates higher-level events that describe one and two finger
 * gestures on the element. The hope is that this will be useful for webapps
 * that need to run on mouse (or trackpad)-based desktop browsers and also in
 * touch-based mobile devices.
 *
 * Supported events:
 *
 *  tap        like a click event
 *  dbltap     like dblclick
 *  pan        one finger motion, or mousedown followed by mousemove
 *  swipe      when a finger is released following pan events
 *  holdstart  touch (or mousedown) and hold. Must set an option to get these.
 *  holdmove   motion after a holdstart event
 *  holdend    when the finger or mouse goes up after holdstart/holdmove
 *  transform  2-finger pinch and twist gestures for scaling and rotation
 *             These are touch-only; they can't be simulated with a mouse.
 *
 * Each of these events is a bubbling CustomEvent with important details in the
 * event.detail field. The event details are not yet stable and are not yet
 * documented. See the calls to emitEvent() for details.
 *
 * To use this library, create a GestureDetector object by passing an element to
 * the GestureDetector() constructor and then calling startDetecting() on it.
 * The element will be the target of all the emitted gesture events. You can
 * also pass an optional object as the second constructor argument. If you're
 * interested in holdstart/holdmove/holdend events, pass {holdEvents:true} as
 * this second argument. Otherwise they will not be generated.
 *
 * Implementation note: event processing is done with a simple finite-state
 * machine. This means that in general, the various kinds of gestures are
 * mutually exclusive. You won't get pan events until your finger or mouse has
 * moved more than a minimum threshold, for example, but it does, the FSM enters
 * a new state in which it can emit pan and swipe events and cannot emit hold
 * events. Similarly, if you've started a 1 finger pan/swipe gesture and
 * accidentally touch with a second finger, you'll continue to get pan events,
 * and won't suddenly start getting 2-finger transform events.
 *
 * This library never calls preventDefault() or stopPropagation on any of the
 * events it processes, so the raw touch or mouse events should still be
 * available for other code to process. It is not clear to me whether this is a
 * feature or a bug.
 */

var GestureDetector = (function() {

  //
  // Constructor
  //
  function GD(e, options) {
    this.element = e;
    this.options = options || {};
    this.state = initialState;
    this.timers = {};
    this.listeningForMouseEvents = true;
  }

  //
  // Public methods
  //

  GD.prototype.startDetecting = function() {
    var self = this;
    eventtypes.forEach(function(t) {
      self.element.addEventListener(t, self);
    });
  };

  GD.prototype.stopDetecting = function() {
    var self = this;
    eventtypes.forEach(function(t) {
      self.element.removeEventListener(t, self);
    });
  };

  //
  // Internal methods
  //

  GD.prototype.handleEvent = function(e) {
    var handler = this.state[e.type];
    if (!handler) return;

    // If this is a touch event handle each changed touch separately
    if (e.changedTouches) {
      // If we ever receive a touch event, then we know we are on a
      // touch device and we stop listening for mouse events. If we
      // don't do that, then the touchstart touchend mousedown mouseup
      // generated by a single tap gesture will cause us to output
      // tap tap dbltap, which is wrong
      if (this.listeningForMouseEvents) {
        this.listeningForMouseEvents = false;
        this.element.removeEventListener('mousedown', this);
      }

      // XXX https://bugzilla.mozilla.org/show_bug.cgi?id=785554
      // causes touchend events to list all touches as changed, so
      // warn if we see that bug
      if (e.type === 'touchend' && e.changedTouches.length > 1) {
        console.warn('gesture_detector.js: spurious extra changed touch on ' +
                     'touchend. See ' +
                     'https://bugzilla.mozilla.org/show_bug.cgi?id=785554');
      }

      for (var i = 0; i < e.changedTouches.length; i++) {
        handler(this, e, e.changedTouches[i]);
        // The first changed touch might have changed the state of the
        // FSM. We need this line to workaround the bug 785554, but it is
        // probably the right thing to have here, even once that bug is fixed.
        handler = this.state[e.type];
      }
    }
    else {    // Otherwise, just dispatch the event to the handler
      handler(this, e);
    }
  };

  GD.prototype.startTimer = function(type, time) {
    this.clearTimer(type);
    var self = this;
    this.timers[type] = setTimeout(function() {
      self.timers[type] = null;
      var handler = self.state[type];
      if (handler)
        handler(self, type);
    }, time);
  };

  GD.prototype.clearTimer = function(type) {
    if (this.timers[type]) {
      clearTimeout(this.timers[type]);
      this.timers[type] = null;
    }
  };

  // Switch to a new FSM state, and call the init() function of that
  // state, if it has one.  The event and touch arguments are optional
  // and are just passed through to the state init function.
  GD.prototype.switchTo = function(state, event, touch) {
    this.state = state;
    if (state.init)
      state.init(this, event, touch);
  };

  GD.prototype.emitEvent = function(type, detail) {
    if (!this.target) {
      console.error('Attempt to emit event with no target');
      return;
    }

    var event = this.element.ownerDocument.createEvent('CustomEvent');
    event.initCustomEvent(type, true, true, detail);
    this.target.dispatchEvent(event);
  };

  //
  // Tuneable parameters
  //
  GD.HOLD_INTERVAL = 1000;     // Hold events after 1000 ms
  GD.PAN_THRESHOLD = 20;       // 20 pixels movement before touch panning
  GD.MOUSE_PAN_THRESHOLD = 15; // Mice are more precise, so smaller threshold
  GD.DOUBLE_TAP_DISTANCE = 50;
  GD.DOUBLE_TAP_TIME = 500;
  GD.VELOCITY_SMOOTHING = .5;

  // Don't start sending transform events until the gesture exceeds a threshold
  GD.SCALE_THRESHOLD = 20;     // pixels
  GD.ROTATE_THRESHOLD = 22.5;  // degrees

  // For pans and zooms, we compute new starting coordinates that are part way
  // between the initial event and the event that crossed the threshold so that
  // the first event we send doesn't cause a big lurch. This constant must be
  // between 0 and 1 and says how far along the line between the initial value
  // and the new value we pick
  GD.THRESHOLD_SMOOTHING = 0.9;

  //
  // Helpful shortcuts and utility functions
  //

  var abs = Math.abs, floor = Math.floor, sqrt = Math.sqrt, atan2 = Math.atan2;
  var PI = Math.PI;

  // The names of events that we need to register handlers for
  var eventtypes = [
    'touchstart',
    'touchmove',
    'touchend',
    'mousedown'  // We register mousemove and mouseup manually
  ];

  // Return the event's timestamp in ms
  function eventTime(e) {
    // In gecko, synthetic events seem to be in microseconds rather than ms.
    // So if the timestamp is much larger than the current time, assue it is
    // in microseconds and divide by 1000
    var ts = e.timeStamp;
    if (ts > 2 * Date.now())
      return Math.floor(ts / 1000);
    else
      return ts;
  }


  // Return an object containg the space and time coordinates of
  // and event and touch. We freeze the object to make it immutable so
  // we can pass it in events and not worry about values being changed.
  function coordinates(e, t) {
    return Object.freeze({
      screenX: t.screenX,
      screenY: t.screenY,
      clientX: t.clientX,
      clientY: t.clientY,
      timeStamp: eventTime(e)
    });
  }

  // Like coordinates(), but return the midpoint between two touches
  function midpoints(e, t1, t2) {
    return Object.freeze({
      screenX: floor((t1.screenX + t2.screenX) / 2),
      screenY: floor((t1.screenY + t2.screenY) / 2),
      clientX: floor((t1.clientX + t2.clientX) / 2),
      clientY: floor((t1.clientY + t2.clientY) / 2),
      timeStamp: eventTime(e)
    });
  }

  // Like coordinates(), but for a mouse event
  function mouseCoordinates(e) {
    return Object.freeze({
      screenX: e.screenX,
      screenY: e.screenY,
      clientX: e.clientX,
      clientY: e.clientY,
      timeStamp: eventTime(e)
    });
  }

  // Given coordinates objects c1 and c2, return a new coordinates object
  // representing a point and time along the line between those points.
  // The position of the point is controlled by the THRESHOLD_SMOOTHING constant
  function between(c1, c2) {
    var r = GD.THRESHOLD_SMOOTHING;
    return Object.freeze({
      screenX: floor(c1.screenX + r * (c2.screenX - c1.screenX)),
      screenY: floor(c1.screenY + r * (c2.screenY - c1.screenY)),
      clientX: floor(c1.clientX + r * (c2.clientX - c1.clientX)),
      clientY: floor(c1.clientY + r * (c2.clientY - c1.clientY)),
      timeStamp: floor(c1.timeStamp + r * (c2.timeStamp - c1.timeStamp))
    });
  }

  // Compute the distance between two touches
  function touchDistance(t1, t2) {
    var dx = t2.screenX - t1.screenX;
    var dy = t2.screenY - t1.screenY;
    return sqrt(dx * dx + dy * dy);
  }

  // Compute the direction (as an angle) of the line between two touches
  // Returns a number d, -180 < d <= 180
  function touchDirection(t1, t2) {
    return atan2(t2.screenY - t1.screenY,
                 t2.screenX - t1.screenX) * 180 / PI;
  }

  // Compute the clockwise angle between direction d1 and direction d2.
  // Returns an angle a -180 < a <= 180.
  function touchRotation(d1, d2) {
    var angle = d2 - d1;
    if (angle > 180)
      angle -= 360;
    else if (angle <= -180)
      angle += 360;
    return angle;
  }

  // Determine if two taps are close enough in time and space to
  // trigger a dbltap event. The arguments are objects returned
  // by the coordinates() function.
  function isDoubleTap(lastTap, thisTap) {
    var dx = abs(thisTap.screenX - lastTap.screenX);
    var dy = abs(thisTap.screenY - lastTap.screenY);
    var dt = thisTap.timeStamp - lastTap.timeStamp;
    return (dx < GD.DOUBLE_TAP_DISTANCE &&
            dy < GD.DOUBLE_TAP_DISTANCE &&
            dt < GD.DOUBLE_TAP_TIME);
  }

  //
  // The following objects are the states of our Finite State Machine
  //

  // In this state we're not processing any gestures, just waiting
  // for an event to start a gesture and ignoring others
  var initialState = {
    name: 'initialState',
    init: function(d) {
      // When we enter or return to the initial state, clear
      // the detector properties that were tracking gestures
      // Don't clear d.lastTap here, though. We need it for dbltap events
      d.target = null;
      d.start = d.last = null;
      d.touch1 = d.touch2 = null;
      d.vx = d.vy = null;
      d.startDistance = d.lastDistance = null;
      d.startDirection = d.lastDirection = null;
      d.lastMidpoint = null;
      d.scaled = d.rotated = null;
    },

    // Switch to the touchstarted state and process the touch event there
    // Once we've started processing a touch gesture we'll ignore mouse events
    touchstart: function(d, e, t) {
      d.switchTo(touchStartedState, e, t);
    },

    // Or if we see a mouse event first, then start processing a mouse-based
    // gesture, and ignore any touch events
    mousedown: function(d, e) {
      d.switchTo(mouseDownState, e);
    }
  };

  // One finger is down but we haven't generated any event yet. We're
  // waiting to see...  If the finger goes up soon, its a tap. If the finger
  // stays down and still, its a hold. If the finger moves its a pan/swipe.
  // And if a second finger goes down, its a transform
  var touchStartedState = {
    name: 'touchStartedState',
    init: function(d, e, t) {
      // Remember the target of the event
      d.target = e.target;
      // Remember the id of the touch that started
      d.touch1 = t.identifier;
      // Get the coordinates of the touch
      d.start = d.last = coordinates(e, t);
      // Start a timer for a hold
      // If we're doing hold events, start a timer for them
      if (d.options.holdEvents)
        d.startTimer('holdtimeout', GD.HOLD_INTERVAL);
    },

    touchstart: function(d, e, t) {
      // If another finger goes down in this state, then
      // go to transform state to start 2-finger gestures.
      d.clearTimer('holdtimeout');
      d.switchTo(transformState, e, t);
    },
    touchmove: function(d, e, t) {
      // Ignore any touches but the initial one
      // This could happen if there was still a finger down after
      // the end of a previous 2-finger gesture, e.g.
      if (t.identifier !== d.touch1)
        return;

      if (abs(t.screenX - d.start.screenX) > GD.PAN_THRESHOLD ||
          abs(t.screenY - d.start.screenY) > GD.PAN_THRESHOLD) {
        d.clearTimer('holdtimeout');
        d.switchTo(panStartedState, e, t);
      }
    },
    touchend: function(d, e, t) {
      // Ignore any touches but the initial one
      if (t.identifier !== d.touch1)
        return;

      // If there was a previous tap that was close enough in time
      // and space, then emit a 'dbltap' event
      if (d.lastTap && isDoubleTap(d.lastTap, d.start)) {
        d.emitEvent('tap', d.start);
        d.emitEvent('dbltap', d.start);
        // clear the lastTap property, so we don't get another one
        d.lastTap = null;
      }
      else {
        // Emit a 'tap' event using the starting coordinates
        // as the event details
        d.emitEvent('tap', d.start);

        // Remember the coordinates of this tap so we can detect double taps
        d.lastTap = coordinates(e, t);
      }

      // In either case clear the timer and go back to the initial state
      d.clearTimer('holdtimeout');
      d.switchTo(initialState);
    },

    holdtimeout: function(d) {
      d.switchTo(holdState);
    }

  };

  // A single touch has moved enough to exceed the pan threshold and now
  // we're going to generate pan events after each move and a swipe event
  // when the touch ends. We ignore any other touches that occur while this
  // pan/swipe gesture is in progress.
  var panStartedState = {
    name: 'panStartedState',
    init: function(d, e, t) {
      // Panning doesn't start until the touch has moved more than a
      // certain threshold. But we don't want the pan to have a jerky
      // start where the first event is a big distance. So proceed as
      // pan actually started at a point along the path between the
      // first touch and this current touch.
      d.start = d.last = between(d.start, coordinates(e, t));

      // If we transition into this state with a touchmove event,
      // then process it with that handler. If we don't do this then
      // we can end up with swipe events that don't know their velocity
      if (e.type === 'touchmove')
        panStartedState.touchmove(d, e, t);
    },

    touchmove: function(d, e, t) {
      // Ignore any fingers other than the one we're tracking
      if (t.identifier !== d.touch1)
        return;

      // Each time the touch moves, emit a pan event but stay in this state
      var current = coordinates(e, t);
      d.emitEvent('pan', {
        absolute: {
          dx: current.screenX - d.start.screenX,
          dy: current.screenY - d.start.screenY
        },
        relative: {
          dx: current.screenX - d.last.screenX,
          dy: current.screenY - d.last.screenY
        },
        position: current
      });

      // Track the pan velocity so we can report this with the swipe
      // Use a exponential moving average for a bit of smoothing
      // on the velocity
      var dt = current.timeStamp - d.last.timeStamp;
      var vx = (current.screenX - d.last.screenX) / dt;
      var vy = (current.screenY - d.last.screenY) / dt;

      if (d.vx == null) { // first time; no average
        d.vx = vx;
        d.vy = vy;
      }
      else {
        d.vx = d.vx * GD.VELOCITY_SMOOTHING +
          vx * (1 - GD.VELOCITY_SMOOTHING);
        d.vy = d.vy * GD.VELOCITY_SMOOTHING +
          vy * (1 - GD.VELOCITY_SMOOTHING);
      }

      d.last = current;
    },
    touchend: function(d, e, t) {
      // Ignore any fingers other than the one we're tracking
      if (t.identifier !== d.touch1)
        return;

      // Emit a swipe event when the finger goes up.
      // Report start and end point, dx, dy, dt, velocity and direction
      var current = coordinates(e, t);
      var dx = current.screenX - d.start.screenX;
      var dy = current.screenY - d.start.screenY;
      // angle is a positive number of degrees, starting at 0 on the
      // positive x axis and increasing clockwise.
      var angle = atan2(dy, dx) * 180 / PI;
      if (angle < 0)
        angle += 360;

      // Direction is 'right', 'down', 'left' or 'up'
      var direction;
      if (angle >= 315 || angle < 45)
        direction = 'right';
      else if (angle >= 45 && angle < 135)
        direction = 'down';
      else if (angle >= 135 && angle < 225)
        direction = 'left';
      else if (angle >= 225 && angle < 315)
        direction = 'up';

      d.emitEvent('swipe', {
        start: d.start,
        end: current,
        dx: dx,
        dy: dy,
        dt: e.timeStamp - d.start.timeStamp,
        vx: d.vx,
        vy: d.vy,
        direction: direction,
        angle: angle
      });

      // Go back to the initial state
      d.switchTo(initialState);
    }
  };

  // We enter this state if the user touches and holds for long enough
  // without moving much.  When we enter we emit a holdstart event. Motion
  // after the holdstart generates holdmove events. And when the touch ends
  // we generate a holdend event. holdmove and holdend events can be used
  // kind of like drag and drop events in a mouse-based UI. Currently,
  // these events just report the coordinates of the touch.  Do we need
  // other details?
  var holdState = {
    name: 'holdState',
    init: function(d) {
      d.emitEvent('holdstart', d.start);
    },

    touchmove: function(d, e, t) {
      var current = coordinates(e, t);
      d.emitEvent('holdmove', {
        absolute: {
          dx: current.screenX - d.start.screenX,
          dy: current.screenY - d.start.screenY
        },
        relative: {
          dx: current.screenX - d.last.screenX,
          dy: current.screenY - d.last.screenY
        },
        position: current
      });

      d.last = current;
    },

    touchend: function(d, e, t) {
      var current = coordinates(e, t);
      d.emitEvent('holdend', {
        start: d.start,
        end: current,
        dx: current.screenX - d.start.screenX,
        dy: current.screenY - d.start.screenY
      });
      d.switchTo(initialState);
    }
  };

  // We enter this state if a second touch starts before we start
  // recoginzing any other gesture.  As the touches move we track the
  // distance and angle between them to report scale and rotation values
  // in transform events.
  var transformState = {
    name: 'transformState',
    init: function(d, e, t) {
      // Remember the id of the second touch
      d.touch2 = t.identifier;

      // Get the two Touch objects
      var t1 = e.touches.identifiedTouch(d.touch1);
      var t2 = e.touches.identifiedTouch(d.touch2);

      // Compute and remember the initial distance and angle
      d.startDistance = d.lastDistance = touchDistance(t1, t2);
      d.startDirection = d.lastDirection = touchDirection(t1, t2);

      // Don't start emitting events until we're past a threshold
      d.scaled = d.rotated = false;
    },

    touchmove: function(d, e, t) {
      // Ignore touches we're not tracking
      if (t.identifier !== d.touch1 && t.identifier !== d.touch2)
        return;

      // Get the two Touch objects
      var t1 = e.touches.identifiedTouch(d.touch1);
      var t2 = e.touches.identifiedTouch(d.touch2);

      // Compute the new midpoints, distance and direction
      var midpoint = midpoints(e, t1, t2);
      var distance = touchDistance(t1, t2);
      var direction = touchDirection(t1, t2);
      var rotation = touchRotation(d.startDirection, direction);

      // Check all of these numbers against the thresholds. Otherwise
      // the transforms are too jittery even when you try to hold your
      // fingers still.
      if (!d.scaled) {
        if (abs(distance - d.startDistance) > GD.SCALE_THRESHOLD) {
          d.scaled = true;
          d.startDistance = d.lastDistance =
            floor(d.startDistance +
                  GD.THRESHOLD_SMOOTHING * (distance - d.startDistance));
        }
        else
          distance = d.startDistance;
      }
      if (!d.rotated) {
        if (abs(rotation) > GD.ROTATE_THRESHOLD)
          d.rotated = true;
        else
          direction = d.startDirection;
      }

      // If nothing has exceeded the threshold yet, then we
      // don't even have to fire an event.
      if (d.scaled || d.rotated) {
        // The detail field for the transform gesture event includes
        // 'absolute' transformations against the initial values and
        // 'relative' transformations against the values from the last
        // transformgesture event.
        d.emitEvent('transform', {
          absolute: { // transform details since gesture start
            scale: distance / d.startDistance,
            rotate: touchRotation(d.startDirection, direction)
          },
          relative: { // transform since last gesture change
            scale: distance / d.lastDistance,
            rotate: touchRotation(d.lastDirection, direction)
          },
          midpoint: midpoint
        });

        d.lastDistance = distance;
        d.lastDirection = direction;
        d.lastMidpoint = midpoint;
      }
    },

    touchend: function(d, e, t) {
      // If either finger goes up, we're done with the gesture.
      // The user might move that finger and put it right back down
      // again to begin another 2-finger gesture, so we can't go
      // back to the initial state while one of the fingers remains up.
      // On the other hand, we can't go back to touchStartedState because
      // that would mean that the finger left down could cause a tap or
      // pan event. So we need an afterTransform state that waits for
      // a finger to come back down or the other finger to go up.
      if (t.identifier === d.touch2)
        d.touch2 = null;
      else if (t.identifier === d.touch1) {
        d.touch1 = d.touch2;
        d.touch2 = null;
      }
      else
        return; // It was a touch we weren't tracking

      // If we emitted any transform events, now we need to emit
      // a transformend event to end the series.  The details of this
      // event use the values from the last touchmove, and the
      // relative amounts will 1 and 0, but they are included for
      // completeness even though they are not useful.
      if (d.scaled || d.rotated) {
        d.emitEvent('transformend', {
          absolute: { // transform details since gesture start
            scale: d.lastDistance / d.startDistance,
            rotate: touchRotation(d.startDirection, d.lastDirection)
          },
          relative: { // nothing has changed relative to the last touchmove
            scale: 1,
            rotate: 0
          },
          midpoint: d.lastMidpoint
        });
      }

      d.switchTo(afterTransformState);
    }
  };

  // We did a tranform and one finger went up. Wait for that finger to
  // come back down or the other finger to go up too.
  var afterTransformState = {
    name: 'afterTransformState',
    touchstart: function(d, e, t) {
      d.switchTo(transformState, e, t);
    },

    touchend: function(d, e, t) {
      if (t.identifier === d.touch1)
        d.switchTo(initialState);
    }
  };

  var mouseDownState = {
    name: 'mouseDownState',
    init: function(d, e) {
      // Remember the target of the event
      d.target = e.target;

      // Register this detector as a *capturing* handler on the document
      // so we get all subsequent mouse events until we remove these handlers
      var doc = d.element.ownerDocument;
      doc.addEventListener('mousemove', d, true);
      doc.addEventListener('mouseup', d, true);

      // Get the coordinates of the mouse event
      d.start = d.last = mouseCoordinates(e);

      // Start a timer for a hold
      // If we're doing hold events, start a timer for them
      if (d.options.holdEvents)
        d.startTimer('holdtimeout', GD.HOLD_INTERVAL);
    },

    mousemove: function(d, e) {
      // If the mouse has moved more than the panning threshold,
      // then switch to the mouse panning state. Otherwise remain
      // in this state

      if (abs(e.screenX - d.start.screenX) > GD.MOUSE_PAN_THRESHOLD ||
          abs(e.screenY - d.start.screenY) > GD.MOUSE_PAN_THRESHOLD) {
        d.clearTimer('holdtimeout');
        d.switchTo(mousePannedState, e);
      }
    },

    mouseup: function(d, e) {
      // Remove the capturing event handlers
      var doc = d.element.ownerDocument;
      doc.removeEventListener('mousemove', d, true);
      doc.removeEventListener('mouseup', d, true);

      // If there was a previous tap that was close enough in time
      // and space, then emit a 'dbltap' event
      if (d.lastTap && isDoubleTap(d.lastTap, d.start)) {
        d.emitEvent('tap', d.start);
        d.emitEvent('dbltap', d.start);
        d.lastTap = null; // so we don't get another one
      }
      else {
        // Emit a 'tap' event using the starting coordinates
        // as the event details
        d.emitEvent('tap', d.start);

        // Remember the coordinates of this tap so we can detect double taps
        d.lastTap = mouseCoordinates(e);
      }

      // In either case clear the timer and go back to the initial state
      d.clearTimer('holdtimeout');
      d.switchTo(initialState);
    },

    holdtimeout: function(d) {
      d.switchTo(mouseHoldState);
    }
  };

  // Like holdState, but for mouse events instead of touch events
  var mouseHoldState = {
    name: 'mouseHoldState',
    init: function(d) {
      d.emitEvent('holdstart', d.start);
    },

    mousemove: function(d, e) {
      var current = mouseCoordinates(e);
      d.emitEvent('holdmove', {
        absolute: {
          dx: current.screenX - d.start.screenX,
          dy: current.screenY - d.start.screenY
        },
        relative: {
          dx: current.screenX - d.last.screenX,
          dy: current.screenY - d.last.screenY
        },
        position: current
      });

      d.last = current;
    },

    mouseup: function(d, e) {
      var current = mouseCoordinates(e);
      d.emitEvent('holdend', {
        start: d.start,
        end: current,
        dx: current.screenX - d.start.screenX,
        dy: current.screenY - d.start.screenY
      });
      d.switchTo(initialState);
    }
  };

  var mousePannedState = {
    name: 'mousePannedState',
    init: function(d, e) {
      // Panning doesn't start until the mouse has moved more than
      // a certain threshold. But we don't want the pan to have a jerky
      // start where the first event is a big distance. So reset the
      // starting point to a point between the start point and this
      // current point
      d.start = d.last = between(d.start, mouseCoordinates(e));

      // If we transition into this state with a mousemove event,
      // then process it with that handler. If we don't do this then
      // we can end up with swipe events that don't know their velocity
      if (e.type === 'mousemove')
        mousePannedState.mousemove(d, e);
    },
    mousemove: function(d, e) {
      // Each time the mouse moves, emit a pan event but stay in this state
      var current = mouseCoordinates(e);
      d.emitEvent('pan', {
        absolute: {
          dx: current.screenX - d.start.screenX,
          dy: current.screenY - d.start.screenY
        },
        relative: {
          dx: current.screenX - d.last.screenX,
          dy: current.screenY - d.last.screenY
        },
        position: current
      });

      // Track the pan velocity so we can report this with the swipe
      // Use a exponential moving average for a bit of smoothing
      // on the velocity
      var dt = current.timeStamp - d.last.timeStamp;
      var vx = (current.screenX - d.last.screenX) / dt;
      var vy = (current.screenY - d.last.screenY) / dt;

      if (d.vx == null) { // first time; no average
        d.vx = vx;
        d.vy = vy;
      }
      else {
        d.vx = d.vx * GD.VELOCITY_SMOOTHING +
          vx * (1 - GD.VELOCITY_SMOOTHING);
        d.vy = d.vy * GD.VELOCITY_SMOOTHING +
          vy * (1 - GD.VELOCITY_SMOOTHING);
      }

      d.last = current;
    },
    mouseup: function(d, e) {
      // Remove the capturing event handlers
      var doc = d.element.ownerDocument;
      doc.removeEventListener('mousemove', d, true);
      doc.removeEventListener('mouseup', d, true);

      // Emit a swipe event when the mouse goes up.
      // Report start and end point, dx, dy, dt, velocity and direction
      var current = mouseCoordinates(e);

      // FIXME:
      // lots of code duplicated between this state and the corresponding
      // touch state, can I combine them somehow?
      var dx = current.screenX - d.start.screenX;
      var dy = current.screenY - d.start.screenY;
      // angle is a positive number of degrees, starting at 0 on the
      // positive x axis and increasing clockwise.
      var angle = atan2(dy, dx) * 180 / PI;
      if (angle < 0)
        angle += 360;

      // Direction is 'right', 'down', 'left' or 'up'
      var direction;
      if (angle >= 315 || angle < 45)
        direction = 'right';
      else if (angle >= 45 && angle < 135)
        direction = 'down';
      else if (angle >= 135 && angle < 225)
        direction = 'left';
      else if (angle >= 225 && angle < 315)
        direction = 'up';

      d.emitEvent('swipe', {
        start: d.start,
        end: current,
        dx: dx,
        dy: dy,
        dt: current.timeStamp - d.start.timeStamp,
        vx: d.vx,
        vy: d.vy,
        direction: direction,
        angle: angle
      });

      // Go back to the initial state
      d.switchTo(initialState);
    }
  };

  return GD;
}());


define("shared/js/gesture_detector", function(){});

/*jshint browser: true */
/*global console, define */

define('iframe_shims',['shared/js/gesture_detector'], function() {



var GestureDetector = window.GestureDetector;

/**
 * Some default styles to override the canonical HTML5 styling defaults that
 * make our display seem bad.  These are currently inline because we want to be
 * able to synchronously (re)flow the document without needing styles to load.
 * This does not need to be the case longterm; after our initial reflow to
 * detect newsletters, we could only add in a link to a CSS file shipped with
 * us for the non-newsletter case.  We could also internally load the CSS file
 * and splice it in rather than hardcoding it.
 */
var DEFAULT_STYLE_TAG =
  '<style type="text/css">\n' +
  // ## blockquote
  // blockquote per html5: before: 1em, after: 1em, start: 4rem, end: 4rem
  'blockquote {' +
  'margin: 0; ' +
  // so, this is quoting styling, which makes less sense to have in here.
  'border-left: 0.2rem solid gray;' +
  // padding-start isn't a thing yet, somehow.
  'padding: 0; -moz-padding-start: 0.5rem; ' +
  '}\n' +
  // Give the layout engine an upper-bound on the width that's arguably
  // much wider than anyone should find reasonable, but might save us from
  // super pathological cases.
  'html, body { max-width: 120rem; }\n' +
  // pre messes up wrapping very badly if left to its own devices
  'pre { white-space: pre-wrap; }\n' +
  '.moz-external-link { color: blue; cursor: pointer; }\n' +
  '</style>';

/**
 * Logic to help with creating, populating, and handling events involving our
 * HTML message-disply iframes.
 *
 * All HTML content is passed through a white-list-based sanitization process,
 * but we still want the iframe so that:
 *
 * - We can guarantee the content can't escape out into the rest of the page.
 * - We can both avoid the content being influenced by our stylesheets as well
 *   as to allow the content to use inline "style" tags without any risk to our
 *   styling.
 * - We MAYBE SOMEDAY get the security benefits of an iframe "sandbox".
 *
 * Our iframe sandbox attributes (not) specified and rationale are:
 * - "allow-same-origin": YES.  We do this because in order to touch the
 *   contentDocument we need to live in the same origin.  Because scripts are
 *   not enabled in the iframe this is not believed to have any meaningful
 *   impact.
 * - "allow-scripts": NO.  We never ever want to let scripts from an email
 *   run.  And since we are setting "allow-same-origin", even if we did want
 *   to allow scripts we *must not* while that setting is on.  Our CSP should
 *   limit the use of scripts if the iframe has the same origin as us since
 *   everything in the iframe should qualify as
 * - "allow-top-navigation": NO.  The iframe should not navigate if the user
 *   clicks on a link.  Note that the current plan is to just capture the
 *   click event and trigger the browse event ourselves so we can show them the
 *   URL, so this is just extra protection.
 * - "allow-forms": NO.  We already sanitize forms out, so this is just extra
 *   protection.
 * - "allow-popups": NO.  We would never want this, but it also shouldn't be
 *   possible to even try to trigger this (scripts are disabled and sanitized,
 *   links are sanitized to forbid link targets as well as being nerfed), so
 *   this is also just extra protection.
 *
 * The spec makes a big deal that flag changes only take effect when navigation
 * occurs.  Accordingly, we may need to actually trigger navigation by using
 * a data URI (currently, and which should be able to inherit our origin)
 * rather than relying on about:blank.  On the other hand, sandbox flags have
 * been added to CSP, so we might also be able to rely on our CSP having set
 * things so that even the instantaneously created about:blank gets locked down.
 *
 * The only wrinkle right now is that gecko does not support the "seamless"
 * attribute.  This is not a problem since our content insertion is synchronous
 * and we can force a size calculation, but it would be nice if we didn't
 * have to do it.
 *
 * ## Document Width and Zooming ##
 *
 * There are two types of HTML e-mails:
 *
 * 1) E-mails written by humans which are basically unstructured prose plus
 *    quoting.  The biggest problems these face are deep quoting causing
 *    blockquote padding to cause text to have very little screen real estate.
 *
 * 2) Newsletter style e-mails which are structured and may have multiple
 *    columns, grids of images and stuff like that.
 *
 * Newsletters tend to assume a screen width of around 60rem.  They also help
 * us out by usually explicitly sizing (parts) of themselves with that big
 * number, but usually a few levels of DOM in.  We could try and look for
 * explicit 'width' style directives (or attributes for tables), possibly
 * during sanitization, or we can try and force the layout engine to figure out
 * how wide the document really wants to be and then figure out if we need
 * a zoom strategy.  The latter approach is more reliable but will result in
 * layout having to perform 2 reflows (although one of them could probably be
 * run during synchronization and persisted).
 *
 * We use the make-layout-figure-it-out strategy and declare any width that
 * ended up being wider than the viewport's width is a newsletter.  We then
 * deal with the cases like so:
 *
 * 1) We force the iframe to be the width of our screen and try and imitate a
 *    seamless iframe by setting the height of the iframe to its scrollHeight.
 *
 * 2) We force the iframe to be the size it wants to be and use transform magic
 *    and gallery interaction logic to let the user pan and zoom to their
 *    heart's content.  We lack the ability to perform reflows-on-zoom like
 *    browser frames can do right now, so this sucks, but not as bad as if we
 *    tried to force the newsletter into a smaller width than it was designed
 *    for.  We could implement some workarounds for this, but it seems useful
 *    to try and drive this in platform.
 *
 * Here's an interesting blog post on font inflation for those that want to
 * know more:
 * http://jwir3.wordpress.com/2012/07/30/font-inflation-fennec-and-you/
 *
 * BUGS BLOCKING US FROM DOING WHAT WE REALLY WANT, MAYBE:
 *
 * - HTML5 iframe sandbox attribute which is landing soon.
 *   https://bugzilla.mozilla.org/show_bug.cgi?id=341604
 *
 * - reflow on zoom doesn't exist yet?
 *   https://bugzilla.mozilla.org/show_bug.cgi?id=710298
 *
 * BUGS MAKING US DO WORKAROUNDS:
 *
 * - iframe "seamless" doesn't work, so we manually need to poke stuff:
 *   https://bugzilla.mozilla.org/show_bug.cgi?id=80713
 *
 * - iframes can't get the web browser pan-and-zoom stuff for free, so we
 *   use logic from the gallery app.
 *   https://bugzilla.mozilla.org/show_bug.cgi?id=775456
 *
 * ATTENTION: ALL KINDS OF CODE IS COPIED AND PASTED FROM THE GALLERY APP TO
 * GIVE US PINCH AND ZOOM.  IF YOU SEE CODE THAT SAYS PHOTO, THAT IS WHY.
 * ALSO, PHOTOS WILL REPLACE EMAIL AS THE MEANS OF COMMUNICATION.
 *
 * Uh, the ^ stuff below should really be @, but it's my jstut syntax that
 * gjslint simply hates, so...
 *
 * ^args[
 *   ^param[htmlStr]
 *   ^param[parentNode]{
 *     The (future) parent node of the iframe.
 *   }
 *   ^param[adjacentNode ^oneof[null HTMLNode]]{
 *     insertBefore semantics.
 *   }
 *   ^param[linkClickHandler ^func[
 *     ^args[
 *       ^param[event]{
 *       }
 *       ^param[linkNode HTMLElement]{
 *         The actual link HTML element
 *       }
 *       ^param[linkUrl String]{
 *         The URL that would be navigated to.
 *       }
 *       ^param[linkText String]{
 *         The text associated with the link.
 *       }
 *     ]
 *   ]]{
 *     The function to invoke when (sanitized) hyperlinks are clicked on.
 *     Currently, the links are always 'a' tags, but we might support image
 *     maps in the future.  (Or permanently rule them out.)
 *   }
 * ]
 */
function createAndInsertIframeForContent(htmlStr, scrollContainer,
                                         parentNode, beforeNode,
                                         interactiveMode,
                                         clickHandler) {
  // Add padding to compensate for scroll-bars in environments (Firefox, not
  // b2g) where they can show up and cause themselves to exist in perpetuity.
  var scrollPad = 16;

  var viewportWidth = parentNode.offsetWidth - scrollPad;
  var viewport = document.createElement('div');
  var title = document.getElementsByClassName('msg-reader-header')[0];
  var header = document.getElementsByClassName('msg-envelope-bar')[0];
  var extraHeight = title.clientHeight + header.clientHeight;
  viewport.setAttribute(
    'style',
    'overflow: hidden; position: relative; ' +
    'width: 100%;');
  var iframe = document.createElement('iframe');

  iframe.setAttribute('sandbox', 'allow-same-origin');
  // Styling!
  // - no visible border
  // - we want to approximate seamless, so turn off overflow and we'll resize
  //   things below.
  // - 60rem wide; this is approximately the standard expected width for HTML
  //   emails.
  iframe.setAttribute(
    'style',
    'position: absolute; ' +
    'border-width: 0;' +
    'overflow: hidden;'
//    'pointer-events: none; ' +
//    '-moz-user-select: none; ' +
//    'width: ' + (scrollWidth) + 'px; ' +
//    'height: ' + (viewportHeight) + 'px;'
  );
  viewport.appendChild(iframe);
  parentNode.insertBefore(viewport, beforeNode);
  //iframe.setAttribute('srcdoc', htmlStr);

  // we want this fully synchronous so we can know the size of the document
  iframe.contentDocument.open();
  iframe.contentDocument.write('<!doctype html><html><head>');
  iframe.contentDocument.write(DEFAULT_STYLE_TAG);
  iframe.contentDocument.write('</head><body>');
  // (currently our sanitization only generates a body payload...)
  iframe.contentDocument.write(htmlStr);
  iframe.contentDocument.write('</body>');
  iframe.contentDocument.close();
  var iframeBody = iframe.contentDocument.documentElement;
  var scrollWidth = iframeBody.scrollWidth;
  var scrollHeight = iframeBody.scrollHeight;

  var newsletterMode = scrollWidth > viewportWidth,
      resizeFrame;

  var scale = Math.min(1, viewportWidth / scrollWidth),
      baseScale = scale,
      lastScale = scale,
      scaleMode = 0;

  viewport.setAttribute(
    'style',
    'padding: 0; border-width: 0; margin: 0; ' +
    'position: relative; ' +
    'overflow: hidden;');
  viewport.style.width = (scrollWidth * scale) + 'px';
  viewport.style.height = (scrollHeight * scale) + 'px';

  // setting iframe.style.height is not sticky, so be heavy-handed.
  // Also, do not set overflow: hidden since we are already clipped by our
  // viewport or our containing card and Gecko slows down a lot because of the
  // extra clipping.
  iframe.setAttribute(
    'style',
    'padding: 0; border-width: 0; margin: 0; ' +
    'transform-origin: top left; ' +
    'pointer-events: none;');
  iframe.style.width = scrollWidth + 'px';

  resizeFrame = function(updateHeight) {
    if (updateHeight) {
      iframe.style.height = '';
      scrollHeight = iframeBody.scrollHeight;
    }
    if (scale !== 1)
      iframe.style.transform = 'scale(' + scale + ')';
    else
      iframe.style.transform = '';
    iframe.style.height =
      ((scrollHeight * Math.max(1, scale)) + scrollPad) + 'px';
    viewport.style.width = (scrollWidth * scale) + 'px';
    viewport.style.height = ((scrollHeight * scale) + scrollPad) + 'px';
  };
  resizeFrame(true);

  var zoomFrame = function(newScale, centerX, centerY) {
    if (newScale === scale)
      return;

    // Our goal is to figure out how to scroll the window so that the
    // location on the iframe corresponding to centerX/centerY maintains
    // its position after zooming.

    // centerX, centerY  are in screen coordinates.  Offset coordinates of
    // the scrollContainer are screen (card) relative, but those of things
    // inside the scrollContainer exist within that coordinate space and
    // do not change as we scroll.
    // console.log('----ZOOM from', scale, 'to', newScale);
    // console.log('cx', centerX, 'cy', centerY,
    //             'vl', viewport.offsetLeft,
    //             'vt', viewport.offsetTop);
    // console.log('sl', scrollContainer.offsetLeft,
    //             'st', scrollContainer.offsetTop);

    // Figure out how much of our iframe is scrolled off the screen.
    var iframeScrolledTop = scrollContainer.scrollTop - extraHeight,
        iframeScrolledLeft = scrollContainer.scrollLeft;

    // and now convert those into iframe-relative coords
    var ix = centerX + iframeScrolledLeft,
        iy = centerY + iframeScrolledTop;

    var scaleDelta = (newScale / scale);

    var vertScrollDelta = iy * scaleDelta,
        horizScrollDelta = ix * scaleDelta;

    scale = newScale;
    resizeFrame();
    scrollContainer.scrollTop = vertScrollDelta + extraHeight - centerY;
    scrollContainer.scrollLeft = horizScrollDelta - centerX;
  };

  var iframeShims = {
    iframe: iframe,
    resizeHandler: function() {
      resizeFrame(true);
    }
  };
  var detectorTarget = viewport;
  var detector = new GestureDetector(detectorTarget);
  // We don't need to ever stopDetecting since the closures that keep it
  // alive are just the event listeners on the iframe.
  detector.startDetecting();
  // Using tap gesture event for URL link handling.
  if (clickHandler) {
    viewport.removeEventListener('click', clickHandler);
    bindSanitizedClickHandler(viewport, clickHandler, null, iframe);
  }
  // If mail is not newsletter mode, ignore zoom/dbtap event handling.
  if (!newsletterMode || interactiveMode !== 'interactive') {
    return iframeShims;
  }
  detectorTarget.addEventListener('dbltap', function(e) {
    var newScale = scale;
    if (lastScale === scale) {
      scaleMode = (scaleMode + 1) % 3;
      switch (scaleMode) {
        case 0:
          newScale = baseScale;
          break;
        case 1:
          newScale = 1;
          break;
        case 2:
          newScale = 2;
          break;
      }
    }
    else {
      // If already zoomed in, zoom out to starting scale
      if (scale > 1) {
        newScale = lastScale;
        scaleMode = 0;
      }
      // Otherwise zoom in to 2x
      else {
        newScale = 2;
        scaleMode = 2;
      }
    }
    lastScale = newScale;
    try {
      zoomFrame(newScale, e.detail.clientX, e.detail.clientY);
    } catch (ex) {
      console.error('zoom bug!', ex, '\n', ex.stack);
    }
  });
  detectorTarget.addEventListener('transform', function(e) {
    var scaleFactor = e.detail.relative.scale;
    var newScale = scale * scaleFactor;
    // Never zoom in farther than 2x
    if (newScale > 2) {
      newScale = 2;
    }
    // And never zoom out farther than baseScale
    else if (newScale < baseScale) {
      newScale = baseScale;
    }
    zoomFrame(newScale,
              e.detail.midpoint.clientX, e.detail.midpoint.clientY);
  });

  return iframeShims;
}

function bindSanitizedClickHandler(target, clickHandler, topNode, iframe) {
  var eventType, node;
  // Variables that only valid for HTML type mail.
  var root, title, header, attachmentsContainer, msgBodyContainer,
      titleHeight, headerHeight, attachmentsHeight,
      msgBodyMarginTop, msgBodyMarginLeft, attachmentsMarginTop,
      iframeDoc, inputStyle;
  // Tap gesture event for HTML type mail and click event for plain text mail
  if (iframe) {
    root = document.getElementsByClassName('scrollregion-horizontal-too')[0];
    title = document.getElementsByClassName('msg-reader-header')[0];
    header = document.getElementsByClassName('msg-envelope-bar')[0];
    attachmentsContainer =
      document.getElementsByClassName('msg-attachments-container')[0];
    msgBodyContainer = document.getElementsByClassName('msg-body-container')[0];
    inputStyle = window.getComputedStyle(msgBodyContainer);
    msgBodyMarginTop = parseInt(inputStyle.marginTop);
    msgBodyMarginLeft = parseInt(inputStyle.marginLeft);
    titleHeight = title.clientHeight;
    headerHeight = header.clientHeight;
    eventType = 'tap';
    iframeDoc = iframe.contentDocument;
  } else {
    eventType = 'click';
  }
  target.addEventListener(
    eventType,
    function clicked(event) {
      if (iframe) {
        // Because the attachments are updating late,
        // get the client height while clicking iframe.
        attachmentsHeight = attachmentsContainer.clientHeight;
        inputStyle = window.getComputedStyle(attachmentsContainer);
        attachmentsMarginTop =
          (attachmentsHeight) ? parseInt(inputStyle.marginTop) : 0;
        var dx, dy;
        var transform = iframe.style.transform || 'scale(1)';
        var scale = transform.match(/(\d|\.)+/g)[0];
        dx = event.detail.clientX + root.scrollLeft - msgBodyMarginLeft;
        dy = event.detail.clientY + root.scrollTop -
             titleHeight - headerHeight -
             attachmentsHeight - attachmentsMarginTop - msgBodyMarginTop;
        node = iframeDoc.elementFromPoint(dx / scale, dy / scale);
      } else {
        node = event.originalTarget;
      }
      while (node !== topNode) {
        if (node.nodeName === 'A') {
          if (node.hasAttribute('ext-href')) {
            clickHandler(event, node, node.getAttribute('ext-href'),
                         node.textContent);
            event.preventDefault();
            event.stopPropagation();
            return;
          }
        }
        node = node.parentNode;
      }
    });
}

return {
  createAndInsertIframeForContent: createAndInsertIframeForContent,
  bindSanitizedClickHandler: bindSanitizedClickHandler
};

});

define('tmpl!cards/folder_picker.html',['tmpl'], function (tmpl) { return tmpl.toDom('<div class="card-folder-picker card">\n  <section class="fld-folders-header skin-organic" role="region">\n    <header>\n      <a href="#" class="fld-accounts-btn">\n        <span class="icon icon-back"></span>\n      </a>\n      <h1 class="fld-folders-header-account-label"></h1>\n    </header>\n  </section>\n  <div class="scrollregion-below-header folder-scroller-region">\n    <div class="fld-folders-container">\n    </div>\n  </div>\n  <div class="fld-nav-toolbar bottom-toolbar">\n    <button class="fld-nav-settings-btn bottom-btn"></button>\n    <h3 class="fld-nav-last-synced">\n      <span class="fld-nav-last-synced-label"\n            data-l10n-id="account-last-synced-label"></span>\n      <span class="fld-nav-last-synced-value"></span>\n    </h3>\n    <span class="fld-nav-account-problem icon collapsed">!</span>\n  </div>\n</div>'); });

define('tmpl!cards/fld/folder_item.html',['tmpl'], function (tmpl) { return tmpl.toDom('<a class="fld-folder-item">\n  <span class="fld-folder-name"></span>\n  <span class="fld-folder-unread"></span>\n</a>'); });

/*global define */
define('date',['require','mail_common'],function(require) {
  // TODO: move common date functions from mail_common into here over time,
  // and then remove this dependency.
  var common = require('mail_common');

  var date = {
    /**
     * Given a node, show a pretty date for its contents.
     * @param {Node} node  the DOM node.
     * @param {Number} timestamp a timestamp like the one retuned
     * from Date.getTime().
     */
    setPrettyNodeDate: function(node, timestamp) {
      if (timestamp) {
        node.dataset.time = timestamp.valueOf();
        node.dataset.compactFormat = true;
        node.textContent = common.prettyDate(timestamp, true);
      } else {
        node.textContent = '';
        node.removeAttribute('data-time');
      }
    }
  };

  return date;
});

// Loader plugin for loading CSS. Does not guarantee loading via onload
// watching, just inserts link tag.
define('css',{
  load: function(id, require, onload, config) {
    if (config.isBuild) {
        return onload();
    }

    var style = document.createElement('link');
    style.type = 'text/css';
    style.rel = 'stylesheet';
    style.href = require.toUrl(id + '.css');
    style.addEventListener('load', onload, false);
    document.head.appendChild(style);
  }
});

/*global define */
define('cards/folder_picker',['require','tmpl!./folder_picker.html','tmpl!./fld/folder_item.html','folder_depth_classes','mail_common','date','model','l10n!','css!style/folder_cards'],function(require) {

var templateNode = require('tmpl!./folder_picker.html'),
    fldFolderItemNode = require('tmpl!./fld/folder_item.html'),
    FOLDER_DEPTH_CLASSES = require('folder_depth_classes'),
    common = require('mail_common'),
    date = require('date'),
    model = require('model'),
    mozL10n = require('l10n!'),
    Cards = common.Cards,
    bindContainerHandler = common.bindContainerHandler;

require('css!style/folder_cards');

function FolderPickerCard(domNode, mode, args) {
  this.domNode = domNode;

  this.foldersContainer =
    domNode.getElementsByClassName('fld-folders-container')[0];
  bindContainerHandler(this.foldersContainer, 'click',
                       this.onClickFolder.bind(this));

  this.accountButton = domNode.getElementsByClassName('fld-accounts-btn')[0];
  this.accountButton
    .addEventListener('click', this.onShowAccounts.bind(this), false);
  domNode.getElementsByClassName('fld-nav-settings-btn')[0]
    .addEventListener('click', this.onShowSettings.bind(this), false);

  this.toolbarAccountProblemNode =
    domNode.getElementsByClassName('fld-nav-account-problem')[0];
  this.lastSyncedAtNode =
    domNode.getElementsByClassName('fld-nav-last-synced-value')[0];

  this._boundUpdateAccount = this.updateAccount.bind(this);
  model.latest('account', this._boundUpdateAccount);
}
FolderPickerCard.prototype = {
  nextCards: ['settings_main', 'account_picker'],

  onShowSettings: function() {
    Cards.pushCard(
      'settings_main', 'default', 'animate', {}, 'left');
  },

  /**
   * Clicking a different account changes the list of folders displayed.  We
   * then trigger a select of the inbox for that account because otherwise
   * things get permutationally complex.
   */
  updateAccount: function(account) {
    var oldAccount = this.curAccount;

    this.mostRecentSyncTimestamp = 0;

    if (oldAccount !== account) {
      this.foldersContainer.innerHTML = '';
      date.setPrettyNodeDate(this.lastSyncedAtNode);

      model.latestOnce('folder', function(folder) {
        this.curAccount = account;

        // - DOM!
        this.updateSelfDom();

        // update header
        this.domNode
            .getElementsByClassName('fld-folders-header-account-label')[0]
            .textContent = account.name;

        // If no current folder, means this is the first startup, do some
        // work to populate the
        if (!this.curFolder) {
          this.curFolder = folder;
        }

        // Clean up any old bindings.
        if (this.foldersSlice) {
          this.foldersSlice.onsplice = null;
          this.foldersSlice.onchange = null;
        }

        this.foldersSlice = model.foldersSlice;

        // since the slice is already populated, generate a fake notification
        this.onFoldersSplice(0, 0, this.foldersSlice.items, true, false);

        // Listen for changes in the foldersSlice.
        // TODO: perhaps slices should implement an event listener
        // interface vs. only allowing one handler. This is slightly
        // dangerous in that other cards may access model.foldersSlice
        // and could decide to set these handlers, wiping these ones
        // out. However, so far folder_picker is the only one that cares
        // about these dynamic updates.
        this.foldersSlice.onsplice = this.onFoldersSplice.bind(this);
        this.foldersSlice.onchange = this.onFoldersChange.bind(this);
      }.bind(this));
    }
  },
  onShowAccounts: function() {
    if (!this.curAccount)
      return;

    // Add account picker before this folder list.
    Cards.pushCard(
      'account_picker', 'navigation', 'animate',
      {
        curAccountId: this.curAccount.id
      },
      // Place to left of message list
      'left');
  },

  onFoldersSplice: function(index, howMany, addedItems,
                             requested, moreExpected) {
    var foldersContainer = this.foldersContainer;

    var folder;
    if (howMany) {
      for (var i = index + howMany - 1; i >= index; i--) {
        folder = this.foldersSlice.items[i];
        foldersContainer.removeChild(folder.element);
      }
    }

    var dirtySyncTime = false;
    var insertBuddy = (index >= foldersContainer.childElementCount) ?
                        null : foldersContainer.children[index],
        self = this;
    addedItems.forEach(function(folder) {
      var folderNode = folder.element = fldFolderItemNode.cloneNode(true);
      folderNode.folder = folder;
      self.updateFolderDom(folder, true);
      foldersContainer.insertBefore(folderNode, insertBuddy);

      if (self.mostRecentSyncTimestamp < folder.lastSyncedAt) {
        self.mostRecentSyncTimestamp = folder.lastSyncedAt;
        dirtySyncTime = true;
      }
    });
    if (dirtySyncTime)
      this.updateLastSyncedUI();
  },

  onFoldersChange: function(folder) {
    if (this.mostRecentSyncTimestamp < folder.lastSyncedAt) {
      this.mostRecentSyncTimestamp = folder.lastSyncedAt;
      this.updateLastSyncedUI();
    }
  },

  updateLastSyncedUI: function() {
    if (this.mostRecentSyncTimestamp) {
      date.setPrettyNodeDate(this.lastSyncedAtNode,
                             this.mostRecentSyncTimestamp);
    } else {
      this.lastSyncedAtNode.textContent = mozL10n.get('account-never-synced');
    }
  },

  updateSelfDom: function(isAccount) {
    var str = isAccount ? mozL10n.get('settings-account-section') :
      this.curAccount.name;
    this.domNode.getElementsByClassName('fld-folders-header-account-label')[0]
      .textContent = str;

    // Update account problem status
    if (this.curAccount.problems.length)
      this.toolbarAccountProblemNode.classList.remove('collapsed');
    else
      this.toolbarAccountProblemNode.classList.add('collapsed');
  },

  updateFolderDom: function(folder, firstTime) {
    var folderNode = folder.element;

    if (firstTime) {
      if (!folder.selectable)
        folderNode.classList.add('fld-folder-unselectable');

      var depthIdx = Math.min(FOLDER_DEPTH_CLASSES.length - 1, folder.depth);
      folderNode.classList.add(FOLDER_DEPTH_CLASSES[depthIdx]);

      folderNode.getElementsByClassName('fld-folder-name')[0]
        .textContent = folder.name;
    }

    if (folder === this.curFolder)
      folderNode.classList.add('fld-folder-selected');
    else
      folderNode.classList.remove('fld-folder-selected');

    // XXX do the unread count stuff once we have that info
  },

  onClickFolder: function(folderNode, event) {
    var folder = folderNode.folder;
    if (!folder.selectable)
      return;

    var oldFolder = this.curFolder;
    this.curFolder = folder;
    this.updateFolderDom(oldFolder);
    this.updateFolderDom(folder);

    this._showFolder(folder);
    Cards.moveToCard(['message_list', 'nonsearch']);
  },

  /**
   * Tell the message-list to show this folder; exists for single code path.
   */
  _showFolder: function(folder) {
    model.changeFolder(folder);
  },

  /**
   * Our card is going away; perform all cleanup except destroying our DOM.
   * This will enable the UI to animate away from our card without weird
   * graphical glitches.
   */
  die: function() {
    model.removeListener('account', this._boundUpdateAccount);
  }
};
Cards.defineCard({
  name: 'folder_picker',
  modes: {
    // Navigation mode acts like a tray
    navigation: {
      tray: true
    },
    movetarget: {
      tray: false
    }
  },
  constructor: FolderPickerCard,
  templateNode: templateNode
});

return FolderPickerCard;
});
