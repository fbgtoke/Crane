// Crane game engine
// Copyright (C) 2019  Fabio Banchelli
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

/******************************************************************************/
/* Crane game engine                                                          */
/******************************************************************************/
/******************************************************************************/

/* Core                                                                       */
#include "Core/Application.hpp"
#include "Core/Layer.hpp"
#include "Core/LayerStack.hpp"
#include "Core/Time.hpp"

/* Math                                                                       */
#include "Math/Mat4.hpp"
#include "Math/MatrixTransform.hpp"
#include "Math/Quat.hpp"
#include "Math/Vec3.hpp"
#include "Math/Vec4.hpp"

/* Render                                                                     */
#include "Render/BufferLayout.hpp"
#include "Render/Camera.hpp"
#include "Render/Font.hpp"
#include "Render/IndexBuffer.hpp"
#include "Render/OrthographicCamera.hpp"
#include "Render/PerspectiveCamera.hpp"
#include "Render/Renderer.hpp"
#include "Render/Shader.hpp"
#include "Render/Text.hpp"
#include "Render/Texture.hpp"
#include "Render/Transform.hpp"
#include "Render/VertexArray.hpp"
#include "Render/VertexBuffer.hpp"

/* Serialization                                                              */
#include "Serialization/BmpReader.hpp"
#include "Serialization/ObjReader.hpp"

/* Window                                                                     */
#include "Window/Event.hpp"
#include "Window/Input.hpp"
#include "Window/Key.hpp"
#include "Window/Window.hpp"