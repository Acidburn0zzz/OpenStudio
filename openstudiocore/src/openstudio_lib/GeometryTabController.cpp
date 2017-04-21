/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2017, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#include "GeometryTabController.hpp"

#include "GeometryTabView.hpp"
#include "GeometryPreviewController.hpp"
#include "GeometryPreviewView.hpp"
#include "GeometryEditorController.hpp"
#include "GeometryEditorView.hpp"

#include "../model/Model.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {

GeometryTabController::GeometryTabController(bool isIP, const model::Model& model)
  : MainTabController(new GeometryTabView(model, "Geometry")),
  m_model(model),
  m_isIP(isIP)
{
  this->mainContentWidget()->addSubTab("Preview", PREVIEW);

  // DLM: comment this out to hide the editor
  this->mainContentWidget()->addSubTab("Editor", EDITOR);

  connect(this->mainContentWidget(), &MainTabView::tabSelected, this, &GeometryTabController::setSubTab);
}

GeometryTabController::~GeometryTabController()
{
  disconnect(this->mainContentWidget(), &MainTabView::tabSelected, this, &GeometryTabController::setSubTab);
}

void GeometryTabController::setSubTab(int index)
{
  if (m_currentIndex == index) {
    return;
  }
  else {
    m_currentIndex = index;
  }

  if (qobject_cast<GeometryPreviewController *>(m_currentController)) {
    // TODO: DLM revist signals
    //disconnect(this, &ConstructionsTabController::toggleUnitsClicked, static_cast<ModelSubTabView*>((qobject_cast<DefaultConstructionSetsController *>(m_currentController))->subTabView()), &ModelSubTabView::toggleUnitsClicked);
    //disconnect(qobject_cast<DefaultConstructionSetsController *>(m_currentController), &DefaultConstructionSetsController::downloadComponentsClicked, this, &ConstructionsTabController::downloadComponentsClicked);
    //disconnect(qobject_cast<DefaultConstructionSetsController *>(m_currentController), &DefaultConstructionSetsController::openLibDlgClicked, this, &ConstructionsTabController::openLibDlgClicked);
  }
  else if (qobject_cast<GeometryEditorController *>(m_currentController)) {
    //disconnect(this, &ConstructionsTabController::toggleUnitsClicked, static_cast<ModelSubTabView*>((qobject_cast<ConstructionsController *>(m_currentController))->subTabView()), &ModelSubTabView::toggleUnitsClicked);
  }
  else if (m_currentController) {
    // Oops! Should never get here
    OS_ASSERT(false);
  }

  switch (index){
  case PREVIEW:
  {
    auto previewController = new GeometryPreviewController(m_isIP, m_model);
    //connect(this, &ConstructionsTabController::toggleUnitsClicked, static_cast<ModelSubTabView*>(defaultConstructionSetsController->subTabView()), &ModelSubTabView::toggleUnitsClicked);
    //connect(defaultConstructionSetsController, &DefaultConstructionSetsController::downloadComponentsClicked, this, &ConstructionsTabController::downloadComponentsClicked);
    //connect(defaultConstructionSetsController, &DefaultConstructionSetsController::openLibDlgClicked, this, &ConstructionsTabController::openLibDlgClicked);
    this->mainContentWidget()->setSubTab(previewController->view());
    m_currentController = previewController;
    break;
  }

  case EDITOR:
  {
    auto editorController = new GeometryEditorController(m_isIP, m_model);
    //connect(this, &ConstructionsTabController::toggleUnitsClicked, static_cast<ModelSubTabView*>(constructionsController->subTabView()), &ModelSubTabView::toggleUnitsClicked);
    this->mainContentWidget()->setSubTab(editorController->view());
    m_currentController = editorController;
    break;
  }
  default:
    OS_ASSERT(false);
    break;
  }
}

} // openstudio