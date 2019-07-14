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

#include "Layer.hpp"

#include <vector>

namespace Crane {

class LayerStack {
public:
  ~LayerStack();

  void addLayer(Layer* layer);

  inline std::vector<Layer*>::iterator begin()
  {
      return m_Layers.begin();
  }

  inline std::vector<Layer*>::iterator end()
  {
    return m_Layers.end();
  }

  inline std::vector<Layer*>::const_iterator begin() const
  {
    return m_Layers.begin();
  }
  inline std::vector<Layer*>::const_iterator end() const
  {
    return m_Layers.end();
  }

  inline std::vector<Layer*>::reverse_iterator rbegin()
  {
      return m_Layers.rbegin();
  }

  inline std::vector<Layer*>::reverse_iterator rend()
  {
    return m_Layers.rend();
  }

  inline std::vector<Layer*>::const_reverse_iterator rbegin() const
  {
    return m_Layers.rbegin();
  }
  inline std::vector<Layer*>::const_reverse_iterator rend() const
  {
    return m_Layers.rend();
  }

private:
  std::vector<Layer*> m_Layers;
};

}