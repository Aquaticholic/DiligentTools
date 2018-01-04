/*     Copyright 2015-2018 Egor Yusov
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#pragma once

#include "LuaWrappers.h"
#include "LuaBindings.h"
#include "EngineObjectParserCommon.h"
#include "ClassMethodBinding.h"

namespace std
{
    DEFINE_ENUM_HASH( Diligent::PRIMITIVE_TOPOLOGY )
}

namespace Diligent
{
    class DrawAttribsParser : public EngineObjectParserBase
    {
    public:
        DrawAttribsParser( class BufferParser *pBuffParser, IRenderDevice *pRenderDevice, lua_State *L );
        static const Char* DrawAttribsLibName;

    protected:
        virtual void CreateObj( lua_State *L );
        virtual void DestroyObj( void *pData );
        virtual void ReadField( lua_State *L, void *pData, const Char *Field );
        virtual void UpdateField( lua_State *L, void *pData, const Char *Field );
        virtual void PushExistingObject( lua_State *L, const void *pObject );

    private:
        int Draw( lua_State * );
        ClassMethodCaller<DrawAttribsParser> m_DrawBinding;

        int DispatchCompute( lua_State * );
        ClassMethodCaller<DrawAttribsParser> m_DispatchComputeBinding;

        EnumMapping<PRIMITIVE_TOPOLOGY> m_PrimTopologyEnumMapping;
        EnumMapping<VALUE_TYPE> m_ValueTypeEnumMapping;

        String m_BufferMetatableName;
    };
}
