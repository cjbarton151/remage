// Copyright (C) 2022 Luigi Pertoldi <gipert@pm.me>
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
// details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef _RMG_GENERATOR_GPS_HH_
#define _RMG_GENERATOR_GPS_HH_

#include <memory>

#include "G4GeneralParticleSource.hh"
#include "G4ThreeVector.hh"
#include "RMGVGenerator.hh"

class G4Event;
class RMGGeneratorGPS : public RMGVGenerator {

  public:

    inline RMGGeneratorGPS() : RMGVGenerator("GPS") {
      fParticleSource = std::make_unique<G4GeneralParticleSource>();
    }

    inline ~RMGGeneratorGPS() = default;

    inline void GeneratePrimariesKinematics(G4Event* event) override {
      fParticleSource->GeneratePrimaryVertex(event);
    }

    void SetParticlePosition(G4ThreeVector vec) override {
      fParticleSource->GetCurrentSource()->GetPosDist()->SetCentreCoords(vec);
    }

  private:

    std::unique_ptr<G4GeneralParticleSource> fParticleSource = nullptr;
};

#endif

// vim: tabstop=2 shiftwidth=2 expandtab
