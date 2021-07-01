#define get_EVT_Constant(n)      do_get_arg(effect, stat, opcode, n)
#define get_EVT_ConstLabel(n)    do_get_arg(effect, stat, opcode, n)
#define get_EVT_VarLabel(n)      do_get_arg(effect, stat, opcode, n)
#define get_EVT_Int(n)           do_get_arg(effect, stat, opcode, n)
#define get_EVT_Float(n)         MemsizeToReal32(do_get_arg(effect, stat, opcode, n))
#define get_EVT_RGB(n)           do_get_arg(effect, stat, opcode, n)
#define get_EVT_RGBA(n)          do_get_arg(effect, stat, opcode, n)


memsize do_get_arg(struct Effect *effect, struct etgeffectstatic *stat, etgfunctioncall *opcode, udword index)
{
    memsize param = opcode->parameter[index].param;

    switch (opcode->parameter[index].type)    
    {
        case EVT_Constant:
            break;
        case EVT_Label:
            dbgAssertOrIgnore(FALSE);
            break;
        case EVT_ConstLabel:
            param = (memsize)stat->constData + param;
            break;
        case EVT_VarLabel:
            param = (memsize)effect->variable + param;
            break;
        default:
            param = *((memsize *)(effect->variable + param));
            break;
    }
    return param;
}


#define funcEntry0(name, ret, func) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    memsize (*func_ptr)(void) = opcode->function; \
    return func_ptr(); \
}

#define funcEntry1(name, ret, func, p0) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    memsize (*func_ptr)(_##p0) = (memsize (*)(_##p0)) opcode->function; \
    return func_ptr(var0); \
}

#define funcEntry2(name, ret, func, p0, p1) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    memsize (*func_ptr)(_##p0, _##p1) = (memsize (*)(_##p0, _##p1)) opcode->function; \
    return func_ptr(var0, var1); \
}

#define funcEntry3(name, ret, func, p0, p1, p2) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    memsize (*func_ptr)(_##p0, _##p1, _##p2) = (memsize (*)(_##p0, _##p1, _##p2)) opcode->function; \
    return func_ptr(var0, var1, var2); \
}

#define funcEntry4(name, ret, func, p0, p1, p2, p3) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    memsize (*func_ptr)(_##p0, _##p1, _##p2, _##p3) = (memsize (*)(_##p0, _##p1, _##p2, _##p3)) opcode->function; \
    return func_ptr(var0, var1, var2, var3); \
}

#define funcEntry5(name, ret, func, p0, p1, p2, p3, p4) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    _##p4 var4 = get_##p4(4); \
    memsize (*func_ptr)(_##p0, _##p1, _##p2, _##p3, _##p4) = (memsize (*)(_##p0, _##p1, _##p2, _##p3, _##p4)) opcode->function; \
    return func_ptr(var0, var1, var2, var3, var4); \
}

#define funcEntry6(name, ret, func, p0, p1, p2, p3, p4, p5) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    _##p4 var4 = get_##p4(4); \
    _##p5 var5 = get_##p5(5); \
    memsize (*func_ptr)(_##p0, _##p1, _##p2, _##p3, _##p4, _##p5) = (memsize (*)(_##p0, _##p1, _##p2, _##p3, _##p4, _##p5)) opcode->function; \
    return func_ptr(var0, var1, var2, var3, var4, var5); \
}

#define funcEntry7(name, ret, func, p0, p1, p2, p3, p4, p5, p6) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    _##p4 var4 = get_##p4(4); \
    _##p5 var5 = get_##p5(5); \
    _##p6 var6 = get_##p6(6); \
    memsize (*func_ptr)(_##p0, _##p1, _##p2, _##p3, _##p4, _##p5, _##p6) = (memsize (*)(_##p0, _##p1, _##p2, _##p3, _##p4, _##p5, _##p6)) opcode->function; \
    return func_ptr(var0, var1, var2, var3, var4, var5, var6); \
}

#define funcEntry8(name, ret, func, p0, p1, p2, p3, p4, p5, p6, p7) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    _##p4 var4 = get_##p4(4); \
    _##p5 var5 = get_##p5(5); \
    _##p6 var6 = get_##p6(6); \
    _##p7 var7 = get_##p7(7); \
    memsize (*func_ptr)(_##p0, _##p1, _##p2, _##p3, _##p4, _##p5, _##p6,  _##p7) = (memsize (*)(_##p0, _##p1, _##p2, _##p3, _##p4, _##p5, _##p6,  _##p7)) opcode->function; \
    return func_ptr(var0, var1, var2, var3, var4, var5, var6, var7); \
}

/**************************************************************************************/

#define funcEntryThis0(name, ret, func) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    memsize (*func_ptr)(void *) = (memsize (*)(void *)) opcode->function; \
    return func_ptr(effect); \
}

#define funcEntryThis1(name, ret, func, p0) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    memsize (*func_ptr)(void *, _##p0) = (memsize (*)(void *, _##p0)) opcode->function; \
    return func_ptr(effect, var0); \
}

#define funcEntryThis2(name, ret, func, p0, p1) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    memsize (*func_ptr)(void *, _##p0, _##p1) = (memsize (*)(void *, _##p0, _##p1)) opcode->function; \
    return func_ptr(effect, var0, var1); \
}

#define funcEntryThis3(name, ret, func, p0, p1, p2) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    memsize (*func_ptr)(void *, _##p0, _##p1, _##p2) = (memsize (*)(void *, _##p0, _##p1, _##p2)) opcode->function; \
    return func_ptr(effect, var0, var1, var2); \
}

#define funcEntryThis4(name, ret, func, p0, p1, p2, p3) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    memsize (*func_ptr)(void *, _##p0, _##p1, _##p2, _##p3) = (memsize (*)(void *, _##p0, _##p1, _##p2, _##p3)) opcode->function; \
    return func_ptr(effect, var0, var1, var2, var3); \
}

#define funcEntryThis5(name, ret, func, p0, p1, p2, p3, p4) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    _##p4 var4 = get_##p4(4); \
    memsize (*func_ptr)(void *, _##p0, _##p1, _##p2, _##p3, _##p4) = (memsize (*)(void *, _##p0, _##p1, _##p2, _##p3, _##p4)) opcode->function; \
    return func_ptr(effect, var0, var1, var2, var3, var4); \
}

#define funcEntryThis6(name, ret, func, p0, p1, p2, p3, p4, p5) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    _##p4 var4 = get_##p4(4); \
    _##p5 var5 = get_##p5(5); \
    memsize (*func_ptr)(void *, _##p0, _##p1, _##p2, _##p3, _##p4, _##p5) = (memsize (*)(void *, _##p0, _##p1, _##p2, _##p3, _##p4, _##p5)) opcode->function; \
    return func_ptr(effect, var0, var1, var2, var3, var4, var5); \
}

#define funcEntryThis7(name, ret, func, p0, p1, p2, p3, p4, p5, p6) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    _##p4 var4 = get_##p4(4); \
    _##p5 var5 = get_##p5(5); \
    _##p6 var6 = get_##p6(6); \
    memsize (*func_ptr)(void *, _##p0, _##p1, _##p2, _##p3, _##p4, _##p5, _##p6) = (memsize (*)(void *, _##p0, _##p1, _##p2, _##p3, _##p4, _##p5, _##p6)) opcode->function; \
    return func_ptr(effect, var0, var1, var2, var3, var4, var5, var6); \
}

#define funcEntryThis8(name, ret, func, p0, p1, p2, p3, p4, p5, p6, p7) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    _##p2 var2 = get_##p2(2); \
    _##p3 var3 = get_##p3(3); \
    _##p4 var4 = get_##p4(4); \
    _##p5 var5 = get_##p5(5); \
    _##p6 var6 = get_##p6(6); \
    _##p7 var7 = get_##p7(7); \
    memsize (*func_ptr)(void *, _##p0, _##p1, _##p2, _##p3, _##p4, _##p5, _##p6, _##p7) = (memsize (*)(void *, _##p0, _##p1, _##p2, _##p3, _##p4, _##p5, _##p6, _##p7)) opcode->function; \
    return func_ptr(effect, var0, var1, var2, var3, var4, var5, var6, var7); \
}

/************************************************/

#define funcEntryR1(name, ret, func, p0, resolve) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    memsize (*func_ptr)(_##p0) = (memsize (*)(_##p0)) opcode->function; \
    return func_ptr(var0); \
}

#define funcEntryR2(name, ret, func, p0, p1, resolve) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    memsize (*func_ptr)(_##p0, _##p1) = (memsize (*)(_##p0, _##p1)) opcode->function; \
    return func_ptr(var0, var1); \
}

/************************************************/

#define funcEntryThisR1(name, ret, func, p0, resolve)  \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    memsize (*func_ptr)(void *, _##p0) = (memsize (*)(void *, _##p0)) opcode->function; \
    return func_ptr(effect, var0); \
}

#define funcEntryThisR2(name, ret, func, p0, p1, resolve) \
memsize wrap_##func(Effect *effect, struct etgeffectstatic *stat ,etgfunctioncall *opcode) \
{ \
    _##p0 var0 = get_##p0(0); \
    _##p1 var1 = get_##p1(1); \
    memsize (*func_ptr)(void *, _##p0, _##p1) = (memsize (*)(void *, _##p0, _##p1)) opcode->function; \
    return func_ptr(effect, var0, var1); \
}

